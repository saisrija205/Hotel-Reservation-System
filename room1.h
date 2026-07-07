#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room
{
private:
    int roomNumber;
    string roomType;
    double roomPrice;
    bool isBooked;

public:

    // Constructors
    Room();
    Room(int number, string type, double price, bool booked);

    // Setters
    void setRoomNumber(int number);
    void setRoomType(string type);
    void setRoomPrice(double price);
    void setBookingStatus(bool booked);

    // Getters
    int getRoomNumber();
    string getRoomType();
    double getRoomPrice();
    bool getBookingStatus();

    // Input & Display
    void inputRoom();
    void displayRoom();

    // File Operations
    void saveRoom();
    void viewRooms();
    bool searchRoom(int number);
    void deleteRoom(int number);
};

#endif