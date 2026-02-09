/*
* Program: Library Management System
* Description:
* This program implements a simple Library Management System using
Object-Oriented Programming concepts in C++. It allows users to add books,
display available books, issue books, and return books using a menu-driven
interface.

* The program demonstrates the use of classes, objects, static data members,
arrays of objects, and member functions.



*/
#include <iostream>
#include <string>
using namespace std;
static int totalBooks = 0;

class Books{
    string bookTitle;
    string author;

public:
    int bookID;
    int copies;

public:
    void addBook()
    {
        static int n = 0;
        cout << "Enter book title:";
        cin >> ws;
        getline(cin, bookTitle);
        cout << "Enter author name:";
        getline(cin, author);
        cout << "Enter total copies:";
        cin >> copies;
        bookID = 1 + n;
        cout << "Book added successfully! \nID no.: " << bookID << endl;
        totalBooks += copies;
        n++;
    }

public:
    void displayBooks()
    {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Copies available: " << copies << endl;
        cout << endl;
        cout << "------------------------" << endl;
    }

public:
    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully!" << endl;
            cout << "Book Title: " << bookTitle << endl;
            cout << "Copies left: " << copies << endl;
        }
        else
        {
            cout << "Sorry, no copies available!" << endl;
        }
    }

public:
    void returnBook()
    {
        copies++;
        cout << "Book returned successfully!" << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Copies available: " << copies << endl;
    }
};
int main(){
    static int count = 0;
    int books;
    Books t1[50];
    cout << "Library Management System" << endl;
    cout << "------------------------" << endl;
    cout << "Menu: \n1. Add book \n2. Display books \n3. Issue book \n4. Return book \n5. Exit" << endl;
    int choice;
    while (true)
    {
        cout << "Enter choice (5 to exit): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            static int i = 0;
            cout << "How many books do you want to add? ";
            cin >> books;
            count += books;
            do
            {
                t1[i].addBook();
                i++;
            } while (--books);
            break;
        }
        case 2:
        {
            cout << "------------------------" << endl;
            cout << "------------------------" << endl;
            cout << "Total books in library: " << totalBooks << endl;
            for (int j = 0; j < count; j++)
            {
                t1[j].displayBooks();
            }
            break;
        }
        case 3:
        {
            cout << "Enter book ID to issue: ";
            int id;
            int flag = 0;
            cin >> id;
            for (int i = 0; i < count; i++)
            {
                if (t1[i].bookID == id)
                {
                    t1[i].issueBook();
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Book with ID " << id << " not found!" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter book ID to return: ";
            int id;
            int flag = 0;
            cin >> id;
            for (int i = 0; i < count; i++)
            {
                if (t1[i].bookID == id)
                {
                    t1[i].returnBook();
                    flag = 1;
                    break;
                }
            }
                if (flag == 0)
                {
                    cout << "Book with ID " << id << " not found!" << endl;
                }
                break;
        }
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}