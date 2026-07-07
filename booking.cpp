#include "booking.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Default Constructor
Booking::Booking()
{
    bookingID = 0;
    roomNumber = 0;
    customerName = "";
    customerPhone = "";
    checkInDate = "";
    checkOutDate = "";
    numberOfDays = 0;
    totalAmount = 0;
}

// Parameterized Constructor
Booking::Booking(int id, int roomNo, string name, string phone,
                 string checkIn, string checkOut,
                 int days, double amount)
{
    bookingID = id;
    roomNumber = roomNo;
    customerName = name;
    customerPhone = phone;
    checkInDate = checkIn;
    checkOutDate = checkOut;
    numberOfDays = days;
    totalAmount = amount;
}

// Setters
void Booking::setBookingID(int id)
{
    bookingID = id;
}

void Booking::setRoomNumber(int roomNo)
{
    roomNumber = roomNo;
}

void Booking::setCustomerName(string name)
{
    customerName = name;
}

void Booking::setCustomerPhone(string phone)
{
    customerPhone = phone;
}

void Booking::setCheckInDate(string date)
{
    checkInDate = date;
}

void Booking::setCheckOutDate(string date)
{
    checkOutDate = date;
}

void Booking::setNumberOfDays(int days)
{
    numberOfDays = days;
}

void Booking::setTotalAmount(double amount)
{
    totalAmount = amount;
}

// Getters
int Booking::getBookingID()
{
    return bookingID;
}

int Booking::getRoomNumber()
{
    return roomNumber;
}

string Booking::getCustomerName()
{
    return customerName;
}

string Booking::getCustomerPhone()
{
    return customerPhone;
}

string Booking::getCheckInDate()
{
    return checkInDate;
}

string Booking::getCheckOutDate()
{
    return checkOutDate;
}

int Booking::getNumberOfDays()
{
    return numberOfDays;
}

double Booking::getTotalAmount()
{
    return totalAmount;
}

// Input Booking
void Booking::inputBooking()
{
    cout << "Enter Booking ID: ";
    cin >> bookingID;

    cout << "Enter Room Number: ";
    cin >> roomNumber;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Customer Phone: ";
    getline(cin, customerPhone);

    cout << "Enter Check-In Date: ";
    getline(cin, checkInDate);

    cout << "Enter Check-Out Date: ";
    getline(cin, checkOutDate);

    cout << "Enter Number of Days: ";
    cin >> numberOfDays;

    cout << "Enter Total Amount: ";
    cin >> totalAmount;
}

// Display Booking
void Booking::displayBooking()
{
    cout << "\n-----------------------------------------\n";
    cout << "Booking ID      : " << bookingID << endl;
    cout << "Room Number     : " << roomNumber << endl;
    cout << "Customer Name   : " << customerName << endl;
    cout << "Phone Number    : " << customerPhone << endl;
    cout << "Check-In Date   : " << checkInDate << endl;
    cout << "Check-Out Date  : " << checkOutDate << endl;
    cout << "Days            : " << numberOfDays << endl;
    cout << "Total Amount    : Rs. " << totalAmount << endl;
}

// Save Booking
void Booking::saveBooking()
{
    ofstream file("bookings.txt", ios::app);

    if (!file)
    {
        cout << "Unable to open bookings.txt\n";
        return;
    }

    file << bookingID << " "
         << roomNumber << " "
         << customerName << " "
         << customerPhone << " "
         << checkInDate << " "
         << checkOutDate << " "
         << numberOfDays << " "
         << totalAmount << endl;

    file.close();

    cout << "\nBooking Saved Successfully.\n";
}

// View All Bookings
void Booking::viewBookings()
{
    ifstream file("bookings.txt");

    if (!file)
    {
        cout << "\nNo Bookings Found.\n";
        return;
    }

    Booking temp;

    while(file >> temp.bookingID
               >> temp.roomNumber
               >> temp.customerName
               >> temp.customerPhone
               >> temp.checkInDate
               >> temp.checkOutDate
               >> temp.numberOfDays
               >> temp.totalAmount)
    {
        temp.displayBooking();
    }

    file.close();
}

// Search Booking
bool Booking::searchBooking(int id)
{
    ifstream file("bookings.txt");

    Booking temp;

    while(file >> temp.bookingID
               >> temp.roomNumber
               >> temp.customerName
               >> temp.customerPhone
               >> temp.checkInDate
               >> temp.checkOutDate
               >> temp.numberOfDays
               >> temp.totalAmount)
    {
        if(temp.bookingID == id)
        {
            temp.displayBooking();
            file.close();
            return true;
        }
    }

    file.close();

    cout << "\nBooking Not Found.\n";
    return false;
}

// Cancel Booking
void Booking::cancelBooking(int id)
{
    ifstream file("bookings.txt");
    ofstream tempFile("temp.txt");

    Booking temp;
    bool found = false;

    while(file >> temp.bookingID
               >> temp.roomNumber
               >> temp.customerName
               >> temp.customerPhone
               >> temp.checkInDate
               >> temp.checkOutDate
               >> temp.numberOfDays
               >> temp.totalAmount)
    {
        if(temp.bookingID == id)
        {
            found = true;
            continue;
        }

        tempFile << temp.bookingID << " "
                 << temp.roomNumber << " "
                 << temp.customerName << " "
                 << temp.customerPhone << " "
                 << temp.checkInDate << " "
                 << temp.checkOutDate << " "
                 << temp.numberOfDays << " "
                 << temp.totalAmount << endl;
    }

    file.close();
    tempFile.close();

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if(found)
        cout << "\nBooking Cancelled Successfully.\n";
    else
        cout << "\nBooking ID Not Found.\n";
}

// Generate Bill
void Booking::generateBill()
{
    cout << "\n====================================\n";
    cout << "          HOTEL BILL\n";
    cout << "====================================\n";
    cout << "Booking ID    : " << bookingID << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Room Number   : " << roomNumber << endl;
    cout << "Check-In      : " << checkInDate << endl;
    cout << "Check-Out     : " << checkOutDate << endl;
    cout << "Days          : " << numberOfDays << endl;
    cout << "------------------------------------\n";
    cout << "Total Amount  : Rs. " << totalAmount << endl;
    cout << "====================================\n";
    cout << "Thank You! Visit Again.\n";
}