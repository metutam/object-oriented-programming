// definition of the user class

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

// usage of the encapsulation:
// declare name-surname, ID, account name and password member variables and
// functions that will set (Set) and return (Get) the values of these variables

class User
{
private:
    string name;
    int userId;
    string accountName;
    string password;

public:
    User(string="NULL", int=0, string="NULL", string="NULL"); // constructor

    void SetName(string);
    void SetUserId(int);
    void SetAccountName(string);
    void SetPassword(string);

    string GetName();
    int GetUserId();
    string GetAccountName();
    string GetPassword();

    bool VerifyUser(string, string); // verifies the name and password of the account for users to access the system
};

#endif