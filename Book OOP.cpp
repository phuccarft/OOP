#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    string genre;
    bool available;

public:
    // Constructor
    Book(int id = 0, string t = "", string a = "", string g = "", bool avail = true)
        : bookID(id), title(t), author(a), genre(g), available(avail) {}

    // Getters
    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    bool isAvailable() const { return available; }

    // Setters
    void setAvailable(bool a) { available = a; }

    // Methods
    void checkOut() {
        if (available) {
            available = false;
            cout << "Book \"" << title << "\" checked out.\n";
        } else {
            cout << "Book \"" << title << "\" is not available.\n";
        }
    }

    void returnBook() {
        available = true;
        cout << "Book \"" << title << "\" returned.\n";
    }
};

// ======= MAIN: test class Book =======
int main() {
    Book b1(1, "Clean Code", "Robert C. Martin", "Programming", true);
    Book b2(2, "C++ Primer", "Lippman", "Programming", true);

    cout << "Book 1: " << b1.getTitle() << " by " << b1.getAuthor() << endl;
    cout << "Book 2: " << b2.getTitle() << " by " << b2.getAuthor() << endl;

    b1.checkOut();   // Muon sach
    b1.checkOut();   // Muon lai (khong duoc)
    b1.returnBook(); // Tra sach

    return 0;
}

