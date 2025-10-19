#include <iostream>
#include <string>
using namespace std;

class Librarian {
private:
    int employeeID;
    string name;

public:
    // Constructor
    Librarian(int id = 0, string n = "")
        : employeeID(id), name(n) {}

    // Getters
    int getEmployeeID() const { return employeeID; }
    string getName() const { return name; }

    // Setters
    void setEmployeeID(int id) { employeeID = id; }
    void setName(const string& n) { name = n; }

    // Methods
    void addBook(const string& bookTitle) {
        cout << "Librarian \"" << name << "\" added book: " << bookTitle << endl;
    }

    void searchBook(const string& title) {
        cout << "Librarian \"" << name << "\" is searching for: " << title << endl;
        cout << "Book \"" << title << "\" found in catalog.\n";
    }
};


int main() {
    Librarian lib1(101, "Nguyen Duy");
    Librarian lib2(102, "Nguyen Nhat Anh Khoi");

    cout << "Librarian 1: " << lib1.getName() << " (ID: " << lib1.getEmployeeID() << ")\n";
    cout << "Librarian 2: " << lib2.getName() << " (ID: " << lib2.getEmployeeID() << ")\n";

    lib1.addBook("Clean Code");
    lib1.searchBook("C++ Primer");

    lib2.addBook("Database Systems");
    lib2.searchBook("Algorithms Unlocked");

    return 0;
}
