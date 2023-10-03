# PROGRAMMING PROJECT 2

In my second programming project, it is expected to write a simple console application (in C++ programming language) that can be used as a library automation program in universities.

The details of the implementation of object-oriented programming using the concepts of class, object and inheritance are listed below:
1. There will be two main classes:
   - **User**
   - **Book**
  
2. There will be two types of users (**Admin**, **Member**) and the classes you will define for both users must be inherited from the base class named **User**.
3. **User** class must consist of name-surname, ID, account name and password member variables and functions that will set (Set) and return (Get) the values of these variables.
4. One of the member functions of the **User** base class should be a **bool** function that will verify the name and password of the account they enter in order for users to access the system.
5. The class defined as **Admin** that is derived from the **User** class should contain the following member functions related to the administration of the system:
   - **Add Member:** This function is used to add a new member to the system. Before adding members, the account name entered for the new member must be checked. Having more than one member with the same account name in the system should be prevented.
   - **Delete Member:** This function ensures that a member defined in the system is deleted from the system.
   - **Add Book:** This function allows a new book to be added to the system.
   - **Delete Book:** This function ensures that a book whose Id is entered is deleted from the system.
   - **List Members:** This function prints all information (values of member variables) of all members defined in the system.
   - **List Books:** This function prints the information of the books registered in the system on the screen.
  
6. The **Member** class to be derived from the **User** class has a member variable named **memberType** that is of string data type, and 3 different values can be assigned to this member variable:
   - Student
   - Personnel
   - Faculty Member
  
7. The class named **Member** derived from the **User** class must contain the following member functions related to the actions that members can perform:
   - **Find Book:** Searches among the books registered in the system by entering the author or book name, returns the information of the searched book or books and presses on the screen.
   - **Borrow Book:** If the book whose ID is entered is not borrowed by another user, the book is borrowed by this member. Lending is done by changing the status of the related book. If the member is a student, he / she can borrow a maximum of 5 books, staff can borrow 3 books and the instructor 10 books.
   - **Return a Book:** A user can return the book for which he has entered his ID into the system. This is done by changing the status of the book. Members can only return books borrowed by themselves.
   - **List Books:** Displays the information about the books registered in the system.
  
8. **Book** class includes properties such as book title, Id, author, year of publication and Get and Set functions belonging to these properties. At the same time, the status of the book must be stored in a member variable. If the book has been borrowed by a member, its status should be "Hold", if it has not been borrowed, its status should be "Unhold". If the book is in "Hold" status, the information on who borrowed the book should also be kept. (For example, the id of the user who borrowed the book can be used for this purpose.)
