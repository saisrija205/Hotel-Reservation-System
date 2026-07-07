 #include <iostream>
#include "hotel.h"

using namespace std;

int main()
{
    Hotel hotel;
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "     HOTEL RESERVATION SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Menu\n";
        cout << "3. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                hotel.adminLogin();
                break;

            case 2:
                hotel.customerMenu();
                break;

            case 3:
                cout << "\nThank you for using Hotel Reservation System.\n";
                cout << "Goodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 3);

    return 0;
}