#ifndef BOOKING_H
#define BOOKING_H

#include <string>

using namespace std;

class Booking
{
private:
    int bookingID;
    int roomNumber;

    string customerName;
    string customerPhone;

    string checkInDate;
    string checkOutDate;

    int numberOfDays;
    double totalAmount;

public:

    // Constructors
    Booking();
    Booking(int id,
            int roomNo,
            string name,
            string phone,
            string checkIn,
            string checkOut,
            int days,
            double amount);

    // Setters
    void setBookingID(int id);
    void setRoomNumber(int roomNo);
    void setCustomerName(string name);
    void setCustomerPhone(string phone);
    void setCheckInDate(string date);
    void setCheckOutDate(string date);
    void setNumberOfDays(int days);
    void setTotalAmount(double amount);

    // Getters
    int getBookingID();
    int getRoomNumber();
    string getCustomerName();
    string getCustomerPhone();
    string getCheckInDate();
    string getCheckOutDate();
    int getNumberOfDays();
    double getTotalAmount();

    // Booking Functions
    void inputBooking();
    void displayBooking();

    void saveBooking();
    void viewBookings();

    bool searchBooking(int id);

    void cancelBooking(int id);

    void generateBill();
};

#endif