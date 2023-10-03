// definition of the admin class

#ifndef ADMIN_H
#define ADMIN_H

#include "member.h"

#include <iomanip> // required to use setw
#include <iostream> // required to use cout and cin
using namespace std;

class Admin: public Member // multilevel inheritance
{
public:
    // passed by reference using & and * symbols
    void AddBook(string, string, int &, int &, int, Book*);
    void DeleteBook(int &, int &, int &, Book*);
    void ListBooks(int &, int &, Book*);
    void AddMember(string, string, string, int &, int &, Member*);
    void ListMembers(int &, int &, Member*);
    void DeleteMember(string, int &, int &, Member*);
};

#endif