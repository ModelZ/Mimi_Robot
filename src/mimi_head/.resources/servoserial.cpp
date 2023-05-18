#include <iostream>
#include <cstring>
#include <unistd.h>
#include <wiringSerial.h>

using namespace std;
string str;

int main()
{
    int serialPort = serialOpen("/dev/ttyACM0", 115200); // Open serial communication port with baud rate of 9600

    if (serialPort == -1) // Check if serial port is opened successfully
    {
        cerr << "Failed to open serial port: " << strerror(errno) <<endl;
        return 1;
    }

    while (true) // keep reading from serial until the program is interrupted
    {
        
        string message;

        // Get message from user input
        cout << "[Pi -> Arduino]: ";
        getline(cin, message); 


        serialPrintf(serialPort, "%s\n", message.c_str()); // Send message to Arduino over serial communication


        // Servo error report
        while (serialDataAvail(serialPort) > 0) {
            char c = serialGetchar(serialPort);
            cout << c;
        }

    

    }

    serialClose(serialPort); // Close serial communication port
    return 0;
}
