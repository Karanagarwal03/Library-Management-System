#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------- Book Class -------------------
class Book {
private:
    int id;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int _id, string _title, string _author) {
        id = _id;
        title = _title;
        author = _author;
        isAvailable = true;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getAvailability() { return isAvailable; }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "? Book borrowed successfully.\n";
        } else {
            cout << "? Book is already borrowed.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "? Book returned successfully.\n";
        } else {
            cout << "? Book was not borrowed.\n";
        }
    }

    void displayBook() {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isAvailable ? "Available" : "Borrowed")
             << endl;
    }
};

// ------------------- Member Class -------------------
class Member {
private:
    int memberId;
    string name;

public:
    Member(int _id, string _name) {
        memberId = _id;
        name = _name;
    }

    int getMemberId() { return memberId; }
    string getName() { return name; }

    void displayMember() {
        cout << "Member ID: " << memberId << " | Name: " << name << endl;
    }
};

// ------------------- Library Class -------------------
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Pre-load data
    Library() {
        // Predefined Books
        books.push_back(Book(101, "C++ Programming", "Bjarne Stroustrup"));
        books.push_back(Book(102, "Data Structures", "Mark Allen Weiss"));
        books.push_back(Book(103, "Operating System Concepts", "Silberschatz"));
        books.push_back(Book(104, "Database System Concepts", "Raghu Ramakrishnan"));

        // Predefined Members
        members.push_back(Member(1, "Alice"));
        members.push_back(Member(2, "Bob"));
        members.push_back(Member(3, "Charlie"));
    }

    // Add a new book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "?? Book added successfully!\n";
    }

    // Search book by title
    void searchBook(string title) {
        bool found = false;
        for (auto &book : books) {
            if (book.getTitle() == title) {
                book.displayBook();
                found = true;
            }
        }
        if (!found)
            cout << "? Book not found.\n";
    }

    // Borrow book by ID
    void borrowBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                book.borrowBook();
                return;
            }
        }
        cout << "? Book ID not found.\n";
    }

    // Return book by ID
    void returnBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                book.returnBook();
                return;
            }
        }
        cout << "? Book ID not found.\n";
    }

    // Display all books
    void displayAllBooks() {
        cout << "\n?? --- Library Books ---\n";
        for (auto &book : books) {
            book.displayBook();
        }
        cout << "-------------------------\n";
    }

    // Display all members
    void displayAllMembers() {
        cout << "\n?? --- Library Members ---\n";
        for (auto &member : members) {
            member.displayMember();
        }
        cout << "--------------------------\n";
    }
};

// ------------------- Main Function -------------------
int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n===== ?? Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Display All Members\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
        }
        else if (choice == 2) {
            string title;
            cin.ignore();
            cout << "Enter Book Title to search: ";
            getline(cin, title);
            lib.searchBook(title);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            lib.borrowBook(id);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
        }
        else if (choice == 5) {
            lib.displayAllBooks();
        }
        else if (choice == 6) {
            lib.displayAllMembers();
        }
        else if (choice == 7) {
            cout << "?? Exiting system. Goodbye!\n";
            break;
        }
        else {
            cout << "? Invalid choice. Try again.\n";
        }
    }

    return 0;
}