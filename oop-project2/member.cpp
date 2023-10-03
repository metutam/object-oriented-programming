// implementation of the member class

#include "member.h"

Member::Member(string newMemberType, int newBorrowUpTo)
{
    memberType = newMemberType;
    borrowUpTo = newBorrowUpTo;
}

void Member::SetMemberType(string newMemberType)
{
    memberType = newMemberType;
}

void Member::SetBorrowUpTo(int newBorrowUpTo)
{
    borrowUpTo = newBorrowUpTo;
}

string Member::GetMemberType()
{
    return memberType;
}

int Member::GetBorrowUpTo()
{
    return borrowUpTo;
}

void Member::FindBook(string bookName, string authorName, int &bookId, int &bookCounter, Book* book)
{
    cout << left << setw(6) << "ID";
    cout << left << setw(13) << "Book Name";
    cout << left << setw(15) << "Author Name";
    cout << left << setw(8) << "Year";
    cout << left << setw(10) << "Status";
    cout << endl;
    for (int i = 0; i < bookCounter; i++)
    {
        if (bookName == "*" && authorName == "*")
        {
            cout << left << setw(6) << book[i].GetBookId();
            cout << left << setw(13) << book[i].GetTitle();
            cout << left << setw(15) << book[i].GetAuthor();
            cout << left << setw(8) << book[i].GetYear();
            cout << left << setw(10) << book[i].GetStatus();
            cout << endl;
        }
        else if (bookName == "*" && authorName == book[i].GetAuthor())
        {
            cout << left << setw(6) << book[i].GetBookId();
            cout << left << setw(13) << book[i].GetTitle();
            cout << left << setw(15) << book[i].GetAuthor();
            cout << left << setw(8) << book[i].GetYear();
            cout << left << setw(10) << book[i].GetStatus();
            cout << endl;
        }
        else if (bookName == book[i].GetTitle() && authorName == "*")
        {
            cout << left << setw(6) << book[i].GetBookId();
            cout << left << setw(13) << book[i].GetTitle();
            cout << left << setw(15) << book[i].GetAuthor();
            cout << left << setw(8) << book[i].GetYear();
            cout << left << setw(10) << book[i].GetStatus();
            cout << endl;
        }
        else if (bookName == book[i].GetTitle() && authorName == book[i].GetAuthor())
        {
            cout << left << setw(6) << book[i].GetBookId();
            cout << left << setw(13) << book[i].GetTitle();
            cout << left << setw(15) << book[i].GetAuthor();
            cout << left << setw(8) << book[i].GetYear();
            cout << left << setw(10) << book[i].GetStatus();
            cout << endl;
        }
    }
}

void Member::BorrowBook(int &counter, int &idOfBook, int &bookId, int &bookCounter, Book* book, Member* member)
{
    if (member[counter].GetBorrowUpTo() <= 0)
    {
        cout << "You have reached the maximum number of books that you can borrow." << endl;
        return;
    }

    if (idOfBook > bookId)
    {
        cout << "Invalid Book Id." << endl;
        return;
    }

    if (book[idOfBook].GetStatus() == "Hold")
    {
        cout << "The book has been borrowed by a member." << endl;
        return;
    }

    member[counter].SetBorrowUpTo(member[counter].GetBorrowUpTo() - 1);
    book[idOfBook].SetStatus("Hold");
    book[idOfBook].SetHolderId(member[counter].GetUserId());

    cout << "Book Borrowed" << endl;
}

void Member::ReturnABook(int &counter, int &idOfBook, int &bookId, int &bookCounter, Book* book, Member* member)
{
    if (idOfBook > bookId)
    {
        cout << "Invalid Book Id." << endl;
        return;
    }

    if (book[idOfBook].GetStatus() == "Unhold")
    {
        cout << "The book is not borrowed by anyone." << endl;
        return;
    }

    if (book[idOfBook].GetHolderId() != member[counter].GetUserId())
    {
        cout << "This book was borrowed by someone else. You cannot return this book." << endl;
        return;
    }

    member[counter].SetBorrowUpTo(member[counter].GetBorrowUpTo() + 1);
    book[idOfBook].SetStatus("Unhold");
    book[idOfBook].SetHolderId(0);

    cout << "Book Returned" << endl;
}

void Member::ListBooks(int &bookId, int &bookCounter, Book* book)
{
    cout << left << setw(6) << "ID";
    cout << left << setw(13) << "Book Name";
    cout << left << setw(15) << "Author Name";
    cout << left << setw(8) << "Year";
    cout << left << setw(10) << "Status";
    cout << endl;
    for (int i = 0; i < bookCounter; i++)
    {
        cout << left << setw(6) << book[i].GetBookId();
        cout << left << setw(13) << book[i].GetTitle();
        cout << left << setw(15) << book[i].GetAuthor();
        cout << left << setw(8) << book[i].GetYear();
        cout << left << setw(10) << book[i].GetStatus();
        cout << endl;
    }
}

void Member::MemberOperations(string memberNewPassword, string memberConfirmNewPassword, int &counter, Member* member)
{
    if (memberNewPassword != memberConfirmNewPassword)
    {
        cout << "Passwords do not match." << endl;
        return;
    }

    member[counter].SetPassword(memberNewPassword);

    cout << "Password Changed" << endl;
}
