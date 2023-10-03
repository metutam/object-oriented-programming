// definition of the book class

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

// usage of the encapsulation:
// declare book title, id, author, year of publication and
// Get and Set functions belonging to these properties

class Book
{
private:
    string title;
    int bookId;
    string author;
    int year;
    string status;
    int holderId;

public:
    Book(string="NULL", int=0, string="NULL", int=1970, string="Unhold", int=0); // constructor
    
    void SetTitle(string);
    void SetBookId(int);
    void SetAuthor(string);
    void SetYear(int);
    void SetStatus(string);
    void SetHolderId(int);

    string GetTitle();
    int GetBookId();
    string GetAuthor();
    int GetYear();
    string GetStatus();
    int GetHolderId();
};

#endif