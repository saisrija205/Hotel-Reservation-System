#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    int customerID;
    string customerName;
    string gender;
    int age;
    string phoneNumber;
    string email;
    string address;

public:

    // Constructors
    Customer();
    Customer(int id, string name, string gen, int age,
             string phone, string mail, string addr);

    // Setters
    void setCustomerID(int id);
    void setCustomerName(string name);
    void setGender(string gen);
    void setAge(int age);
    void setPhoneNumber(string phone);
    void setEmail(string mail);
    void setAddress(string addr);

    // Getters
    int getCustomerID();
    string getCustomerName();
    string getGender();
    int getAge();
    string getPhoneNumber();
    string getEmail();
    string getAddress();

    // Input & Display
    void inputCustomer();
    void displayCustomer();

    // File Operations
    void saveCustomer();
    void viewCustomers();
    bool searchCustomer(int id);
    void deleteCustomer(int id);
};

#endif