// vs code -> tasks.json -> "${file}" -> "${workspaceFolder}\\Project2\\*.cpp"

#include "user.h"
#include "admin.h"
#include "member.h"
#include "book.h"

#include <iostream>
using namespace std;

int main()
{
    Book book[100];     // keeps the books in the system in static arrays
    Member member[100]; // keeps the members registered in the system in static arrays

    int choise; // declares the expression of switch-case programming structure

    Admin admin; // creates the admin object from admin class

    int bookId = 0;
    int userId = 0;

    int bookCounter = 0;
    int userCounter = 0;

    string adminUserName;
    string adminPassword;

    string bookName;
    string authorName;
    int yearOfPublication;

    string memberName;
    string memberAccountName;
    string memberType;

    string memberUserName;
    string memberPassword;

    string memberNewPassword;
    string memberConfirmNewPassword;

    int idOfBook;

    string nameOfAccount;

    int counter;
    string nameOfMemberAccount;

    do
    {
        cout << "---Main Menu---\n";
        cout << "1. Admin Login\n";
        cout << "2. Member Login\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choise: ";
        cin >> choise;
        // prints the main menu

        switch (choise) // implements the main menu with the switch-case programming structure
        {
            case 1: // executes when the user selects 1 for admin login
                admin.SetName("Admin");
                admin.SetUserId(0);
                admin.SetAccountName("admin");
                admin.SetPassword("1234");
                // updates the username of the admin object as admin and the password to 1234

                do
                {
                    cout << "Admin User Name: ";
                    cin >> adminUserName;
                    cout << "Password: ";
                    cin >> adminPassword;
                    // gets the username and password of the admin from the keyboard
                } while (!admin.VerifyUser(adminUserName, adminPassword)); // checks whether the entered username and password are correct

                do
                {
                    cout << "---Admin Menu---\n";
                    cout << "1. Add Book\n";
                    cout << "2. Delete Book\n";
                    cout << "3. List Books\n";
                    cout << "4. Add Member\n";
                    cout << "5. List Members\n";
                    cout << "6. Delete Member\n";
                    cout << "7. Exit\n";
                    cout << "Enter Your Choise: ";
                    cin >> choise;
                    // prints the admin menu

                    switch (choise) // implements the sub-menu with the switch-case programming structure
                    {
                        case 1: // executes when the user selects 1 to add a new book to the system
                            cout << "Book Name: ";
                            cin >> bookName;
                            cout << "Author Name: ";
                            cin >> authorName;
                            cout << "Year of Publication: ";
                            cin >> yearOfPublication;
                            // gets the information about the book on the keyboard

                            admin.AddBook(bookName, authorName, bookId, bookCounter, yearOfPublication, book);
                            break;
                        case 2: // executes when the user selects 2 to delete a book stored in the system
                            cout << "Book's Id: ";
                            cin >> idOfBook;
                            // gets the book's Id from the keyboard

                            admin.DeleteBook(idOfBook, bookId, bookCounter, book);
                            break;
                        case 3: // executes when the user selects 3 to display the books stored in the system
                            admin.ListBooks(bookId, bookCounter, book);
                            break;
                        case 4: // executes when the user selects 4 to add a new member to the system
                            cout << "Enter Member Info" << endl;
                            cout << "Name Surname: ";
                            cin >> memberName;
                            cout << "Account Name: ";
                            cin >> memberAccountName;
                            cout << "Member Type: ";
                            cin >> memberType;
                            // gets  the member name, account name and member type from the keyboard

                            admin.AddMember(memberName, memberAccountName, memberType, userId, userCounter, member);
                            break;
                        case 5: // executes when the user selects 5 to display all members registered in the system on the screen
                            admin.ListMembers(userId, userCounter, member);
                            break;
                        case 6: // executes when the user selects 6 to delete a registered member in the system
                            cout << "Account Name: ";
                            cin >> nameOfAccount;
                            // gets the account name information from the screen

                            admin.DeleteMember(nameOfAccount, userId, userCounter, member);
                            break;
                        case 7: // executes when the user selects 7 to exit the admin menu
                            cout << "Exited" << endl;
                            break;
                        default: // executes when the user selects an invalid number
                            cout << "Please enter a valid number." << endl;
                            break;
                    }
                } while (choise != 7 && cin); // at the end of the every process, goes back to the admin menu
                                              // cin returns 0 when the user enters string instead of integer for a variable that declared as an integer
                break;
            case 2: // executes when the user selects 2 for member login
                do
                {
                    cout << "Member User Name: ";
                    cin >> memberUserName;
                    cout << "Password: ";
                    cin >> memberPassword;
                    // gets the account name and password of the member from the keyboard

                    counter = 0;
                    while (counter < userCounter)
                    { // finds the index number of that member
                        nameOfMemberAccount = member[counter].GetAccountName();

                        if (memberUserName == nameOfMemberAccount)
                        {
                            break;
                        }

                        counter++;
                    }
                } while (!member[counter].VerifyUser(memberUserName, memberPassword)); // checks whether the entered account name and password are correct

                do
                {
                    cout << "---Member Menu---\n";
                    cout << "1. Find Book\n";
                    cout << "2. Borrow Book\n";
                    cout << "3. Return Book\n";
                    cout << "4. List Books\n";
                    cout << "5. Member Operations\n";
                    cout << "6. Exit\n";
                    cout << "Enter Your Choise: ";
                    cin >> choise;
                    // prints the member menu

                    switch (choise) // implements the sub-menu with the switch-case programming structure
                    {
                        case 1: // executes when the user selects 1 to search for a book in the system
                            cout << "Enter book name: ";
                            cin >> bookName;
                            cout << "Enter author name: ";
                            cin >> authorName;
                            // gets the title of the book and the name of the author

                            member[counter].FindBook(bookName, authorName, bookId, bookCounter, book);
                            break;
                        case 2: // executes when the user selects 2 to borrow a book
                            cout << "Book Id: ";
                            cin >> idOfBook;
                            // gets the book id from the keyboard

                            member[counter].BorrowBook(counter, idOfBook, bookId, bookCounter, book, member);
                            break;
                        case 3: // executes when the user selects 3 to return books
                            cout << "Book Id: ";
                            cin >> idOfBook;
                            // gets the book id from the keyboard

                            member[counter].ReturnABook(counter, idOfBook, bookId, bookCounter, book, member);
                            break;
                        case 4: // executes when the user selects 4 to list all the books registered in the system
                            member[counter].ListBooks(bookId, bookCounter, book);
                            break;
                        case 5: // executes when the user selects 5 to update the member password by entering a new password
                            cout << "New Password: ";
                            cin >> memberNewPassword;
                            cout << "Confirm New Password: ";
                            cin >> memberConfirmNewPassword;
                            // gets the new password information from the member

                            member[counter].MemberOperations(memberNewPassword, memberConfirmNewPassword, counter, member);
                            break;
                        case 6: // executes when the user selects 6 to exit the member menu
                            cout << "Exited" << endl;
                            break;
                        default: // executes when the user selects an invalid number
                            cout << "Please enter a valid number." << endl;
                            break;
                    }
                } while (choise != 6 && cin); // at the end of the every process, goes back to the member menu
                                              // cin returns 0 when the user enters string instead of integer for a variable that declared as an integer
                break;
            case 3: // executes when the user selects 3 to log out of the system
                cout << "Exited" << endl;
                break;
            default: // executes when the user selects an invalid number
                cout << "Please enter a valid number." << endl;
                break;
        }
    } while (choise != 3 && cin); // at the end of the every process, goes back to the main menu
                                  // cin returns 0 when the user enters string instead of integer for a variable that declared as an integer
}
