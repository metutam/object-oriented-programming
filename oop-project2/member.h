// definition of the member class

#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "book.h"

#include <iomanip> // required to use setw
#include <iostream> // required to use cout and cin
using namespace std;

class Member: public User, public Book // multiple inheritance
{
private:
    string memberType;
    int borrowUpTo;

public:
    Member(string="NULL", int=0); // constructor

    void SetMemberType(string);
    void SetBorrowUpTo(int);

    string GetMemberType();
    int GetBorrowUpTo();

    // passed by reference using & and * symbols
    void FindBook(string, string, int &, int &, Book*);
    void BorrowBook(int &, int &, int &, int &, Book*, Member*);
    void ReturnABook(int &, int &, int &, int &, Book*, Member*);
    void ListBooks(int &, int &, Book*);
    void MemberOperations(string, string, int &, Member*);
};

#endif