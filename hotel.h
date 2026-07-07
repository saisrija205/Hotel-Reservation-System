#ifndef HOTEL_H
#define HOTEL_H

class Hotel
{
private:
    // Admin credentials
    const int adminPassword = 1234;

public:
    // Constructor
    Hotel();

    // Main Menus
    void adminLogin();
    void adminMenu();
    void customerMenu();

    // Room Operations
    void addRoom();
    void viewRooms();
    void deleteRoom();

    // Booking Operations
    void bookRoom();
    void searchBooking();
    void cancelBooking();
    void checkout();
    void viewBookings();

    // Utility
    void generateBill(int roomNo, int days, int pricePerDay);
};

#endif