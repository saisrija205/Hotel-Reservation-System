#include <iostream>
#include "hotel.h"

using namespace std;

// Constructor
Hotel::Hotel()
{
    cout << "\nHotel Reservation System Loaded Successfully.\n";
}

// Admin Login
void Hotel::adminLogin()
{
    int password;

    cout << "\n========== ADMIN LOGIN ==========\n";
    cout << "Enter Admin Password: ";
    cin >> password;

    if (password == adminPassword)
    {
        cout << "\nLogin Successful!\n";
        adminMenu();
    }
    else
    {
        cout << "\nIncorrect Password!\n";
    }
}

// Admin Menu
void Hotel::adminMenu()
{
    int choice;

    do
    {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. Add Room\n";
        cout << "2. View Rooms\n";
        cout << "3. Delete Room\n";
        cout << "4. View Bookings\n";
        cout << "5. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addRoom();
                break;

            case 2:
                viewRooms();
                break;

            case 3:
                deleteRoom();
                break;

            case 4:
                viewBookings();
                break;

            case 5:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}

// Customer Menu
void Hotel::customerMenu()
{
    int choice;

    do
    {
        cout << "\n========== CUSTOMER MENU ==========\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Search Booking\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Checkout\n";
        cout << "6. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                viewRooms();
                break;

            case 2:
                bookRoom();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cancelBooking();
                break;

            case 5:
                checkout();
                break;

            case 6:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);
}

// ----------------------
// Room Functions
// ----------------------

void Hotel::addRoom()
{
    cout << "\n[Add Room Module]\n";
    cout << "This feature will be implemented in room.cpp.\n";
}

void Hotel::viewRooms()
{
    cout << "\n[View Rooms Module]\n";
    cout << "This feature will be implemented in room.cpp.\n";
}

void Hotel::deleteRoom()
{
    cout << "\n[Delete Room Module]\n";
    cout << "This feature will be implemented in room.cpp.\n";
}

// ----------------------
// Booking Functions
// ----------------------

void Hotel::bookRoom()
{
    cout << "\n[Book Room Module]\n";
    cout << "This feature will be implemented in booking.cpp.\n";
}

void Hotel::searchBooking()
{
    cout << "\n[Search Booking Module]\n";
    cout << "This feature will be implemented in booking.cpp.\n";
}

void Hotel::cancelBooking()
{
    cout << "\n[Cancel Booking Module]\n";
    cout << "This feature will be implemented in booking.cpp.\n";
}

void Hotel::checkout()
{
    cout << "\n[Checkout Module]\n";
    cout << "This feature will be implemented in booking.cpp.\n";
}

void Hotel::viewBookings()
{
    cout << "\n[View Bookings Module]\n";
    cout << "This feature will be implemented in booking.cpp.\n";
}

// ----------------------
// Bill Generation
// ----------------------

void Hotel::generateBill(int roomNo, int days, int pricePerDay)
{
    int total = days * pricePerDay;

    cout << "\n=================================\n";
    cout << "         HOTEL BILL\n";
    cout << "=================================\n";
    cout << "Room Number   : " << roomNo << endl;
    cout << "Days Stayed   : " << days << endl;
    cout << "Price Per Day : Rs. " << pricePerDay << endl;
    cout << "---------------------------------\n";
    cout << "Total Amount  : Rs. " << total << endl;
    cout << "=================================\n";
    cout << "Thank You! Visit Again.\n";
}