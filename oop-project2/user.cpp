// implementation of the book class

#include "user.h"

User::User(string newName, int newUserId, string newAccountName, string newPassword)
{
    name = newName;
    userId = newUserId;
    accountName = newAccountName;
    password = newPassword;
}

void User::SetName(string newName)
{
    name = newName;
}

void User::SetUserId(int newUserId)
{
    userId = newUserId;
}

void User::SetAccountName(string newAccountName)
{
    accountName = newAccountName;
}

void User::SetPassword(string newPassword)
{
    password = newPassword;
}

string User::GetName()
{
    return name;
}

int User::GetUserId()
{
    return userId;
}

string User::GetAccountName()
{
    return accountName;
}

string User::GetPassword()
{
    return password;
}

bool User::VerifyUser(string enteredName, string enteredPassword)
{
    if (accountName == enteredName && password == enteredPassword)
    {
        cout << "Password accepted." << endl;
        return true;
    }
    else
    {
        cout << "Username or/and password is incorrect." << endl;
        return false;
    }
}
