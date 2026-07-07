#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager
{
public:
    // Constructor
    FileManager();

    // Room File Operations
    void createRoomFile();
    void displayRoomFile();

    // Customer File Operations
    void createCustomerFile();
    void displayCustomerFile();

    // Booking File Operations
    void createBookingFile();
    void displayBookingFile();

    // Utility Functions
    bool fileExists(string fileName);
    void clearFile(string fileName);
};

#endif