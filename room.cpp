#include "room.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Default Constructor
Room::Room()
{
    roomNumber = 0;
    roomType = "";
    roomPrice = 0.0;
    isBooked = false;
}

// Parameterized Constructor
Room::Room(int number, string type, double price, bool booked)
{
    roomNumber = number;
    roomType = type;
    roomPrice = price;
    isBooked = booked;
}

//----------------------
// Setters
//----------------------

void Room::setRoomNumber(int number)
{
    roomNumber = number;
}

void Room::setRoomType(string type)
{
    roomType = type;
}

void Room::setRoomPrice(double price)
{
    roomPrice = price;
}

void Room::setBookingStatus(bool booked)
{
    isBooked = booked;
}

//----------------------
// Getters
//----------------------

int Room::getRoomNumber()
{
    return roomNumber;
}

string Room::getRoomType()
{
    return roomType;
}

double Room::getRoomPrice()
{
    return roomPrice;
}

bool Room::getBookingStatus()
{
    return isBooked;
}

//----------------------
// Input Room Details
//----------------------

void Room::inputRoom()
{
    cout << "\nEnter Room Number : ";
    cin >> roomNumber;

    cout << "Enter Room Type (Standard/Deluxe/Suite): ";
    cin >> roomType;

    cout << "Enter Room Price : ";
    cin >> roomPrice;

    isBooked = false;
}

//----------------------
// Display Room
//----------------------

void Room::displayRoom()
{
    cout << left
         << setw(12) << roomNumber
         << setw(15) << roomType
         << setw(12) << roomPrice
         << setw(12) << (isBooked ? "Booked" : "Available")
         << endl;
}

//----------------------
// Save Room
//----------------------

void Room::saveRoom()
{
    ofstream file("rooms.txt", ios::app);

    if (!file)
    {
        cout << "Error opening rooms.txt\n";
        return;
    }

    file << roomNumber << " "
         << roomType << " "
         << roomPrice << " "
         << isBooked << endl;

    file.close();

    cout << "\nRoom Added Successfully.\n";
}

//----------------------
// View All Rooms
//----------------------

void Room::viewRooms()
{
    ifstream file("rooms.txt");

    if (!file)
    {
        cout << "\nNo Room Records Found.\n";
        return;
    }

    Room temp;

    cout << "\n-----------------------------------------------------------\n";
    cout << left
         << setw(12) << "Room No"
         << setw(15) << "Type"
         << setw(12) << "Price"
         << setw(12) << "Status"
         << endl;
    cout << "-----------------------------------------------------------\n";

    while (file >> temp.roomNumber
                >> temp.roomType
                >> temp.roomPrice
                >> temp.isBooked)
    {
        temp.displayRoom();
    }

    file.close();
}

//----------------------
// Search Room
//----------------------

bool Room::searchRoom(int number)
{
    ifstream file("rooms.txt");

    if (!file)
        return false;

    Room temp;

    while (file >> temp.roomNumber
                >> temp.roomType
                >> temp.roomPrice
                >> temp.isBooked)
    {
        if (temp.roomNumber == number)
        {
            roomNumber = temp.roomNumber;
            roomType = temp.roomType;
            roomPrice = temp.roomPrice;
            isBooked = temp.isBooked;

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//----------------------
// Delete Room
//----------------------

void Room::deleteRoom(int number)
{
    ifstream file("rooms.txt");
    ofstream tempFile("temp.txt");

    Room temp;
    bool found = false;

    while (file >> temp.roomNumber
                >> temp.roomType
                >> temp.roomPrice
                >> temp.isBooked)
    {
        if (temp.roomNumber == number)
        {
            found = true;
            continue;
        }

        tempFile << temp.roomNumber << " "
                 << temp.roomType << " "
                 << temp.roomPrice << " "
                 << temp.isBooked << endl;
    }

    file.close();
    tempFile.close();

    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");

    if (found)
        cout << "\nRoom Deleted Successfully.\n";
    else
        cout << "\nRoom Not Found.\n";
}