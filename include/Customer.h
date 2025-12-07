#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer{
private:
    long customerID;
    string name;
    string address;
    string phone;
    double bonus;
    string email;
    string username;
    string password;
public:
   //cınstructor
    Customer();
    Customer(long id, const string& n, const string& u, const string& p);

//ıd fonksiyonlari
    long getCustomerID()const;
    void setCustomerID(long customerID);

//name
    string getName()const;
    void setName(const string& name);

//address
    string getAddress()const;
    void setAddress(const string& address);

//phone
    string getPhone()const;
    void setPhone(const string& phone);

//bonus
    double getBonus()const;
    void setBonus(double bonus);

//mail
    string getEmail()const;
    void setEmail(const string& email);

//username
    string getUsername()const;
    void setUsername(const string& username);

//password
    string getPassword()const;
    void setPassword(const string& password);

// Diðer Metotlar (Functionalities)
    void sendBill();
    bool checkAccount(const std::string& uname, const std::string& pass) const;
    void addBonus(double bonusAmount);
    void useBonus();
    void printProperties() const;
    ~Customer();

};

#endif // CUSTOMER_H
