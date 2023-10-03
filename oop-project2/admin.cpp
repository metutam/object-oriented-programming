// implementation of the admin class

#include "admin.h"

void Admin::AddBook(string bookName, string authorName, int &bookId, int &bookCounter, int yearOfPublication, Book* book)
{
    for (int i = 0; i <= bookCounter; i++)
    {
        if (bookName == book[i].GetTitle() && authorName == book[i].GetAuthor() && yearOfPublication == book[i].GetYear())
        {
            cout << "This book already exists." << endl;
            return;
        }
    }

    book[bookCounter].SetTitle(bookName);
    book[bookCounter].SetAuthor(authorName);
    book[bookCounter].SetBookId(bookId);
    book[bookCounter].SetYear(yearOfPublication);

    cout << "Book Added" << endl;

    bookId++;
    bookCounter++;
}

void Admin::DeleteBook(int &idOfBook, int &bookId, int &bookCounter, Book* book)
{
    if (idOfBook > bookId)
    {
        cout << "Invalid Book Id." << endl;
        return;
    }
    
    for (int i = idOfBook; i <= bookId; i++)
    {
        book[i].SetTitle(book[i+1].GetTitle());
        book[i].SetAuthor(book[i+1].GetAuthor());
        book[i].SetBookId(book[i+1].GetBookId());
        book[i].SetYear(book[i+1].GetYear());
        book[i].SetStatus(book[i+1].GetStatus());
    }

    cout << "Book Deleted" << endl;

    bookCounter--;
}

void Admin::ListBooks(int &bookId, int &bookCounter, Book* book)
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

void Admin::AddMember(string memberName, string memberAccountName, string memberType, int &memberId, int &memberCounter, Member* member)
{
    if (memberType != "Student" && memberType != "Personnel" && memberType != "FacultyMember")
    {
        cout << "Member type must be Student, Personnel or FacultyMember." << endl;
        return;
    }

    for (int i = 0; i <= memberCounter; i++)
    {
        if (memberAccountName == member[i].GetAccountName())
        {
            cout << "There must be only one member with the same account name in the system." << endl;
            return;
        }
    }

    member[memberCounter].SetName(memberName);
    member[memberCounter].SetAccountName(memberAccountName);
    member[memberCounter].SetMemberType(memberType);
    member[memberCounter].SetUserId(memberId);
    member[memberCounter].SetPassword("temp");

    if (member[memberCounter].GetMemberType() == "Student")
    {
        member[memberCounter].SetBorrowUpTo(5);
    }
    else if (member[memberCounter].GetMemberType() == "Personnel")
    {
        member[memberCounter].SetBorrowUpTo(3);
    }
    else if (member[memberCounter].GetMemberType() == "FacultyMember")
    {
        member[memberCounter].SetBorrowUpTo(10);
    }

    cout << "Member Added" << endl;

    memberId++;
    memberCounter++;
}

void Admin::ListMembers(int &memberId, int &memberCounter, Member* member)
{
    cout << left << setw(6) << "ID";
    cout << left << setw(15) << "Member Name";
    cout << left << setw(15) << "Member Type";
    cout << left << setw(23) << "Member Account Name";
    cout << endl;
    for (int i = 0; i < memberCounter; i++)
    {
        cout << left << setw(6) << member[i].GetUserId();
        cout << left << setw(15) << member[i].GetName();
        cout << left << setw(15) << member[i].GetMemberType();
        cout << left << setw(23) << member[i].GetAccountName();
        cout << endl;
    }
}

void Admin::DeleteMember(string nameOfAccount, int &memberId, int &memberCounter, Member* member)
{
    int idOfMember;
    int counter = 0;
    while (counter < memberCounter)
    {
        if (nameOfAccount == member[counter].GetAccountName())
        {
            idOfMember = member[counter].GetUserId();
            break;
        }
        counter++;
    }
    if (counter == memberCounter)
    {
        cout << "Member Not Found" << endl;
        return;
    }

    for (int i = idOfMember; i <= memberId; i++)
    {
        member[i].SetName(member[i+1].GetName());
        member[i].SetAccountName(member[i+1].GetAccountName());
        member[i].SetMemberType(member[i+1].GetMemberType());
        member[i].SetUserId(member[i+1].GetUserId());
        member[i].SetPassword(member[i+1].GetPassword());
        member[i].SetBorrowUpTo(member[i+1].GetBorrowUpTo());

    }

    cout << "Member Deleted" << endl;

    memberCounter--;
}
