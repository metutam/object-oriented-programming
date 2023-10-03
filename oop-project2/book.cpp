// implementation of the book class

#include "book.h"

Book::Book(string newTitle, int newBookId, string newAuthor, int newYear, string newStatus, int newHolderId)
{
    title = newTitle;
    bookId = newBookId;
    author = newAuthor;
    year = newYear;
    status = newStatus;
    holderId = newHolderId;
}

void Book::SetTitle(string newTitle)
{
    title = newTitle;
}

void Book::SetBookId(int newBookId)
{
    bookId = newBookId;
}

void Book::SetAuthor(string newAuthor)
{
    author = newAuthor;
}

void Book::SetYear(int newYear)
{
    year = newYear;
}

void Book::SetStatus(string newStatus)
{
    status = newStatus;
}

void Book::SetHolderId(int newHolderId)
{
    holderId = newHolderId;
}

string Book::GetTitle()
{
    return title;
}

int Book::GetBookId()
{
    return bookId;
}

string Book::GetAuthor()
{
    return author;
}

int Book::GetYear()
{
    return year;
}

string Book::GetStatus()
{
    return status;
}

int Book::GetHolderId()
{
    return holderId;
}
