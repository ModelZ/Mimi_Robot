#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <cv_bridge/cv_bridge.h>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "mimi_head/msg/movement.hpp"

using namespace std;
using namespace cv;

//Global Variables
VideoCapture cap; // mimi_vision
Point2i center_closest_face_rect; // closest face rectangle

class MimiCameraNode : public rclcpp::Node
{
    public:

        const int cam_width = 1280;
        const int cam_height = 720;

        MimiCameraNode() : Node("mimi_camera_node")
        {

            // create publisher and set topic
            // this->create_publisher<$msg_type>($topic_name, $QoS);
            cam_publisher_ = this->create_publisher<sensor_msgs::msg::Image>(
                "mimi_vision_monitor", 10
            );

            movement_publisher_ = this->create_publisher<mimi_head::msg::Movement>(
                "head_movement", 10
            );

            // create new parameter
            this->declare_parameter("cam_width", cam_width);
            this->declare_parameter("cam_height", cam_height);
            this->declare_parameter("ratio_x", 0.05);
            this->declare_parameter("ratio_z", 0.02);

            thread mimi_cam(std::bind(&MimiCameraNode::mimi_camera, this));

            mimi_cam.detach();

        }
    
    private:

        Mat videoImage;

        void pub_cam_to_monitor()
        {
            auto img = sensor_msgs::msg::Image();

            //cv_bridge  cv_image -> ros2_image
            auto image_msg_ptr = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", videoImage).toImageMsg();
            img = *image_msg_ptr;

            cam_publisher_->publish(img);
        }

        void mimi_camera()
        {
            //*** Initial OpenCV ****

            // Open Camera Class 0 is index of camera (If multiple)
            cap = VideoCapture(0);

            //set resolution
            cap.set(CAP_PROP_FRAME_WIDTH, this->get_parameter("cam_width").as_int());
            cap.set(CAP_PROP_FRAME_HEIGHT, this->get_parameter("cam_height").as_int());

            //Read File Image Classification
            CascadeClassifier face_cascade = CascadeClassifier("detect/haarcascade_frontalface_default.xml");

            //Face Classification


            vector<Rect> faceDetect; // Vector of rectangles

            double scaleFactor = 1.3; // Parameter specifying how much the image size is reduced at each image scale.
            int minNeighbors = 10; // Parameter specifying how many neighbors each candidate rectangle should have to retain it.

            // print out
            std::cout << "mimi_camera_node node is running...." << std::endl;

            // Loop until a shutdown signal is received
            while (cap.isOpened())
            {
                cap.read(videoImage); // read image from video frame by frame

                if (videoImage.empty()) {
                    std::cerr << "Error: input image is empty" << std::endl;
                    //continue;
                }

                // Convert Image to gray image
                Mat grayImage;
                
                if(!videoImage.empty())
                    cvtColor(videoImage, grayImage, COLOR_BGR2GRAY);

                if (face_cascade.empty()) {
                    std::cerr << "Error: face_cascade is empty" << std::endl;
                   // continue;
                }

                face_cascade.detectMultiScale(grayImage, faceDetect, scaleFactor, minNeighbors); //Face Classification

                Rect closest_face_rect;
                Point2i center;

                // Show face position found in rectangle form
                for (Rect found : faceDetect)
                {
                    center = ((found.br() + found.tl()) / 2); // center point of rectangle

                    rectangle(videoImage, found, { 0,255,0 }, 5); // draw rectangle around human face
                    circle(videoImage, center, 0, {0,255,0}, -1); // draw a center point of rectangle


                    // {x, y} Text above rectangle
                    putText(videoImage, "{" + to_string(found.x) + " , " + to_string(found.y) + "}" , {found.x, found.y}, FONT_HERSHEY_SIMPLEX, 1, {0,255,0}, LINE_8);
                    // {x, y} Text above center point
                    putText(videoImage, "{" + to_string(center.x) + " , " + to_string(center.y) + "}" , {center.x, center.y}, FONT_HERSHEY_SIMPLEX, 1, {0,255,0}, LINE_8);
                    
                    //find the closest face rectangle
                    if(found.area() > closest_face_rect.area())
                    {
                        closest_face_rect = found;
                        // send to global var
                        center_closest_face_rect = center;
                    }
                }
                
                //logger debug & publish movement
                if(!closest_face_rect.empty())
                {         
                    RCLCPP_INFO(this->get_logger(), "found closest face at: {%d, %d}, Center: {%d, %d}", closest_face_rect.x, closest_face_rect.y, center.x, center.y);
                    
                    // publish movement
                    if(!is_timer_active)
                        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&MimiCameraNode::pub_movement, this));
                    is_timer_active = true;
                    // this->pub_movement();
                }   
                else if(is_timer_active){
                    //stop movement
                    auto msg_pub_unknown = mimi_head::msg::Movement();
                    msg_pub_unknown.pos_x = "unknown";
                    msg_pub_unknown.pos_z = "unknown";
                    movement_publisher_->publish(msg_pub_unknown);

                    timer_->cancel();
                    is_timer_active = false;
                } 


                //call publisher
                this->pub_cam_to_monitor();


                

               // waitKey(20);

            }

            //*** End OpenCV ****
        }

        void pub_movement()
        {
            auto msg_movement = mimi_head::msg::Movement();

            const float MAXIMUM_ANGLE_X = 180.0;
            const float MINIMUM_ANGLE_X = 0.0;
            const float MAXIMUM_ANGLE_Z = 170.0;
            const float MINIMUM_ANGLE_Z = 45.0;

            int cam_width = this->get_parameter("cam_width").as_int();
            int cam_height = this->get_parameter("cam_height").as_int();
            float ratio_x = this->get_parameter("ratio_x").as_double();
            float ratio_z = this->get_parameter("ratio_z").as_double();
            float center_cam_width = (float)cam_width / 2.0;
            float center_cam_height = (float)cam_height / 2.0;

            // movement x

            float px_x = (float)center_closest_face_rect.x; // define x axis in pixel
            float diff_px_x = center_cam_width - px_x; // define different of x axis and center of camera
            int limit_x = 64; // center area of point x

            // turning checking x axis

            if(diff_px_x > limit_x){ // destination is right side 

                msg_movement.pos_x = "right";

            }else if(diff_px_x < -limit_x){ // destination is left side 
            
                msg_movement.pos_x = "left";

            }else{ // destination is current position
            
                msg_movement.pos_x = "ok";

            }

            // movement z

            float px_z = (float)center_closest_face_rect.y; // define z axis in pixel
            float diff_px_z = center_cam_height - px_z; // define different of z axis and center of camera
            int limit_z = 64; // center area of point z

            // turning checking z axis

            if(diff_px_z > limit_z){ // destination is above

                msg_movement.pos_z = "up";    

            } else if(diff_px_z < -limit_z){ // destination is below

                msg_movement.pos_z = "down";   

            }else { // destination is current position
                msg_movement.pos_z = "ok";
            }

            //debug
            cout << "msg_movement.pos_x -> " << msg_movement.pos_x << endl <<
            "msg_movement.pos_z -> " << msg_movement.pos_z << endl;

            // publish movement message
            movement_publisher_->publish(msg_movement);
            
        }

        bool is_timer_active = false;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr cam_publisher_;
        rclcpp::Publisher<mimi_head::msg::Movement>::SharedPtr movement_publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

};

void sigint_handler(int sig)
{
    cap.release();
    destroyAllWindows();
    rclcpp::shutdown();
    exit(0);
}

int main(int argc, char * argv[]){

    // Set up signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MimiCameraNode>());
    rclcpp::shutdown();
    cap.release(); //close video
    destroyAllWindows(); //close all windows  


    return 0;
}