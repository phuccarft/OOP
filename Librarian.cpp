#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool available;

public:
    Book(int id = 0, string t = "", string a = "", bool avail = true)
        : bookID(id), title(t), author(a), available(avail) {}

    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void showInfo() const {
        cout << "- " << title << " by " << author
             << (available ? " [Available]" : " [Checked out]") << endl;
    }
};

class Catalog {
private:
    vector<Book> books;

public:
    void addBook(const Book& b) {
        books.push_back(b);
        cout << " Book \"" << b.getTitle() << "\" added to catalog.\n";
    }

    const Book* searchByTitle(const string& title) const {
        for (const auto& b : books)
            if (b.getTitle() == title)
                return &b;
        return nullptr;
    }

    void showAll() const {
        if (books.empty()) {
            cout << "\n Catalog is empty.\n";
            return;
        }
        cout << "\n Catalog contains:\n";
        for (const auto& b : books)
            b.showInfo();
    }
};

class Librarian {
private:
    int employeeID;
    string name;

public:
    Librarian(int id = 0, string n = "") : employeeID(id), name(n) {}

    void addBookInteractive(Catalog& c) {
        int id;
        string title, author;
        cout << "\n Enter new book information:\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);

        Book b(id, title, author, true);
        c.addBook(b);
    }

    void searchBook(Catalog& c) {
        string title;
        cout << "\n Enter book title to search: ";
        cin.ignore();
        getline(cin, title);

        const Book* found = c.searchByTitle(title);
        if (found)
            cout << " Found \"" << found->getTitle() << "\" by " << found->getAuthor() << endl;
        else
            cout << " Sorry, \"" << title << "\" not found in catalog.\n";
    }
};

int main() {
    Catalog catalog;
    Librarian librarian(01, "Nguyen Duy");

    int choice;
    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add a new book\n";
        cout << "2. Show all books\n";
        cout << "3. Search for a book\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                librarian.addBookInteractive(catalog);
                break;
            case 2:
                catalog.showAll();
                break;
            case 3:
                librarian.searchBook(catalog);
                break;
            case 0:
                cout << " Goodbye!\n";
                break;
            default:
                cout << " Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
