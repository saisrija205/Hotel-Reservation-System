#include "customer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;

// Default Constructor
Customer::Customer()
{
    customerID = 0;
    customerName = "";
    gender = "";
    age = 0;
    phoneNumber = "";
    email = "";
    address = "";
}

// Parameterized Constructor
Customer::Customer(int id, string name, string gen, int a,
                   string phone, string mail, string addr)
{
    customerID = id;
    customerName = name;
    gender = gen;
    age = a;
    phoneNumber = phone;
    email = mail;
    address = addr;
}

// --------------------
// Setters
// --------------------

void Customer::setCustomerID(int id)
{
    customerID = id;
}

void Customer::setCustomerName(string name)
{
    customerName = name;
}

void Customer::setGender(string gen)
{
    gender = gen;
}

void Customer::setAge(int a)
{
    age = a;
}

void Customer::setPhoneNumber(string phone)
{
    phoneNumber = phone;
}

void Customer::setEmail(string mail)
{
    email = mail;
}

void Customer::setAddress(string addr)
{
    address = addr;
}

// --------------------
// Getters
// --------------------

int Customer::getCustomerID()
{
    return customerID;
}

string Customer::getCustomerName()
{
    return customerName;
}

string Customer::getGender()
{
    return gender;
}

int Customer::getAge()
{
    return age;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

string Customer::getEmail()
{
    return email;
}

string Customer::getAddress()
{
    return address;
}

// --------------------
// Input Customer
// --------------------

void Customer::inputCustomer()
{
    cout << "\nEnter Customer ID: ";
    cin >> customerID;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Address: ";
    getline(cin, address);
}

// --------------------
// Display Customer
// --------------------

void Customer::displayCustomer()
{
    cout << "\n====================================\n";
    cout << "Customer ID   : " << customerID << endl;
    cout << "Name          : " << customerName << endl;
    cout << "Gender        : " << gender << endl;
    cout << "Age           : " << age << endl;
    cout << "Phone         : " << phoneNumber << endl;
    cout << "Email         : " << email << endl;
    cout << "Address       : " << address << endl;
    cout << "====================================\n";
}

// --------------------
// Save Customer
// --------------------

void Customer::saveCustomer()
{
    ofstream file("customers.txt", ios::app);

    if (!file)
    {
        cout << "Error opening customers.txt\n";
        return;
    }

    file << customerID << "|"
         << customerName << "|"
         << gender << "|"
         << age << "|"
         << phoneNumber << "|"
         << email << "|"
         << address << endl;

    file.close();

    cout << "\nCustomer Saved Successfully.\n";
}

// --------------------
// View Customers
// --------------------

void Customer::viewCustomers()
{
    ifstream file("customers.txt");

    if (!file)
    {
        cout << "\nNo Customer Records Found.\n";
        return;
    }

    string line;

    cout << "\n========== CUSTOMER LIST ==========\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// --------------------
// Search Customer
// --------------------

bool Customer::searchCustomer(int id)
{
    ifstream file("customers.txt");

    if (!file)
    {
        cout << "\nCustomer file not found.\n";
        return false;
    }

    string line;

    while (getline(file, line))
    {
        size_t pos = line.find('|');

        if (pos != string::npos)
        {
            int storedID = stoi(line.substr(0, pos));

            if (storedID == id)
            {
                cout << "\nCustomer Found:\n";
                cout << line << endl;

                file.close();
                return true;
            }
        }
    }

    file.close();

    cout << "\nCustomer Not Found.\n";
    return false;
}

// --------------------
// Delete Customer
// --------------------

void Customer::deleteCustomer(int id)
{
    ifstream file("customers.txt");
    ofstream temp("temp.txt");

    if (!file)
    {
        cout << "\nCustomer file not found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line))
    {
        size_t pos = line.find('|');

        if (pos != string::npos)
        {
            int storedID = stoi(line.substr(0, pos));

            if (storedID == id)
            {
                found = true;
                continue;
            }
        }

        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("customers.txt");
    rename("temp.txt", "customers.txt");

    if (found)
        cout << "\nCustomer Deleted Successfully.\n";
    else
        cout << "\nCustomer ID Not Found.\n";
}