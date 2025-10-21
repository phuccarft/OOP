#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include "Loan.h"      
#include "Catalog.h"   // <-- Include Catalog
#include <iostream>
#include <limits>
#include <chrono>      
#include <iomanip>     

// We need to add our new menu option
void Library::run() {
    int choice = 0;
    while (choice != 7) { // <-- Changed exit to 7
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le. Vui long nhap so.\n";
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: addMember(); break;
            case 2: addBook(); break;
            case 3: viewCatalog(); break; // <-- New option
            case 4: loanBook(); break; 
            case 5: returnBook(); break; 
            case 6: calculateFee(); break;
            case 7: std::cout << "Tam biet!\n"; break; // <-- Changed exit to 7
            default: std::cout << "Lua chon khong hop le. Thu lai.\n";
        }
        std::cout << "\n";
    }
}

// Add the new option to the menu text
void Library::showMenu() {
    std::cout << "--- HE THONG QUAN LY THU VIEN ---\n";
    std::cout << "1. Them thanh vien (Student/Teacher)\n";
    std::cout << "2. Them sach moi\n";
    std::cout << "3. Hien thi danh muc sach (View Catalog)\n"; // <-- New
    std::cout << "4. Muon sach\n";
    std::cout << "5. Tra sach\n";
    std::cout << "6. Tinh phi tre han\n";
    std::cout << "7. Thoat\n"; // <-- New
    std::cout << "Nhap lua chon cua ban: ";
}

// Your addMember() and overloaded addMember() are unchanged...
void Library::addMember() { /* ... no change ... */ }
void Library::addMember(std::string name, std::string id, std::string type) { /* ... no change ... */ }


// --- MODIFIED FUNCTION ---
void Library::addBook() {
    std::string title, author, isbn;
    std::cout << "Nhap tieu de sach: ";
    std::getline(std::cin, title);
    std::cout << "Nhap tac gia: ";
    std::getline(std::cin, author);
    std::cout << "Nhap ma ISBN: ";
    std::getline(std::cin, isbn);

    // Create a book object
    Book newBook(title, author, isbn);
    // Add it to the catalog object
    catalog.addBook(newBook); 

    std::cout << "Da them sach: " << title << "\n";
}

// Your calculateFee() is unchanged...
void Library::calculateFee() { /* ... no change ... */ }

// Your findMemberByID() is unchanged...
Member* Library::findMemberByID(std::string id) { /* ... no change ... */ }

// --- REMOVED FUNCTION ---
// This function is now inside Catalog.cpp
// Book* Library::findBookByIsbn(std::string isbn) { ... }

// --- MODIFIED FUNCTION ---
void Library::loanBook() {
    std::string memberID, isbn;
    std::cout << "Nhap ID thanh vien muon sach: ";
    std::getline(std::cin, memberID);
    
    Member* member = findMemberByID(memberID);
    if (member == nullptr) {
        std::cout << "Loi: Khong tim thay thanh vien.\n";
        return;
    }

    std::cout << "Nhap ma ISBN cua sach: ";
    std::getline(std::cin, isbn);

    // Use the catalog object to find the book
    Book* book = catalog.findBookByIsbn(isbn); 
    if (book == nullptr) {
        std::cout << "Loi: Khong tim thay sach.\n";
        return;
    }

    if (!book->isAvailable()) {
        std::cout << "Loi: Sach \"" << book->getTitle() << "\" hien dang duoc muon.\n";
        return;
    }

    loans.push_back(Loan(book, member)); 
    std::cout << "THANH CONG: " << member->getName() << " da muon \"" 
              << book->getTitle() << "\".\n";
}

// --- MODIFIED FUNCTION ---
void Library::returnBook() {
    std::string isbn;
    std::cout << "Nhap ma ISBN cua sach can tra: ";
    std::getline(std::cin, isbn);

    // Use the catalog object to find the book
    Book* book = catalog.findBookByIsbn(isbn);
    if (book == nullptr) {
        std::cout << "Loi: Khong tim thay sach nay trong he thong.\n";
        return;
    }

    Loan* loan = findActiveLoan(book);
    if (loan == nullptr) {
        std::cout << "Loi: Sach nay hien khong co ai muon (hoac da duoc tra).\n";
        return;
    }

    loan->returnBook();
    std::cout << "THANH CONG: Sach \"" << book->getTitle() << "\" da duoc tra boi " 
              << loan->member->getName() << ".\n";

    int daysLate = loan->getDaysLate();
    if (daysLate > 0) {
        double fee = loan->member->calculateLateFee(daysLate);
        std::cout << "!!! SACH BI TRE HAN " << daysLate << " ngay.\n";
        std::cout << "    Tong phi tre han la: $" << fee << "\n";
    }
}

// Your findActiveLoan() is unchanged...
Loan* Library::findActiveLoan(Book* book) { /* ... no change ... */ }

// --- NEW FUNCTION ---
// This just calls the catalog's display method
void Library::viewCatalog() {
    catalog.displayAllBooks();
}

// Your destructor is unchanged...
Library::~Library() { /* ... no change ... */ }
