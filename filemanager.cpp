#include "filemanager.h"

using namespace std;

// Constructor
FileManager::FileManager()
{
    // Empty Constructor
}

// Check if file exists
bool FileManager::fileExists(string fileName)
{
    ifstream file(fileName);

    if(file)
    {
        file.close();
        return true;
    }

    return false;
}

// Create rooms.txt
void FileManager::createRoomFile()
{
    if(!fileExists("rooms.txt"))
    {
        ofstream file("rooms.txt");
        file.close();
        cout << "rooms.txt created successfully.\n";
    }
    else
    {
        cout << "rooms.txt already exists.\n";
    }
}

// Display rooms.txt
void FileManager::displayRoomFile()
{
    ifstream file("rooms.txt");

    if(!file)
    {
        cout << "Unable to open rooms.txt\n";
        return;
    }

    string line;

    cout << "\n========== ROOMS ==========\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// Create customers.txt
void FileManager::createCustomerFile()
{
    if(!fileExists("customers.txt"))
    {
        ofstream file("customers.txt");
        file.close();
        cout << "customers.txt created successfully.\n";
    }
    else
    {
        cout << "customers.txt already exists.\n";
    }
}

// Display customers.txt
void FileManager::displayCustomerFile()
{
    ifstream file("customers.txt");

    if(!file)
    {
        cout << "Unable to open customers.txt\n";
        return;
    }

    string line;

    cout << "\n========== CUSTOMERS ==========\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// Create bookings.txt
void FileManager::createBookingFile()
{
    if(!fileExists("bookings.txt"))
    {
        ofstream file("bookings.txt");
        file.close();
        cout << "bookings.txt created successfully.\n";
    }
    else
    {
        cout << "bookings.txt already exists.\n";
    }
}

// Display bookings.txt
void FileManager::displayBookingFile()
{
    ifstream file("bookings.txt");

    if(!file)
    {
        cout << "Unable to open bookings.txt\n";
        return;
    }

    string line;

    cout << "\n========== BOOKINGS ==========\n";

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// Clear a file
void FileManager::clearFile(string fileName)
{
    ofstream file(fileName, ios::trunc);

    if(file)
    {
        cout << fileName << " has been cleared successfully.\n";
    }
    else
    {
        cout << "Error clearing " << fileName << endl;
    }

    file.close();
}