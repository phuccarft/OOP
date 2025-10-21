#include <iostream>
#include "Library.h"
#include "Student.h"
#include "Teacher.h"

// Destructor: Cleans up dynamically allocated memory for members
Library::~Library() {
    for (Member* member : members) {
        delete member;
    }
    // The 'loans' vector contains objects, not pointers, so it cleans up itself.
    // The 'catalog' object also cleans up its own memory.
}

// Main application loop (for the console app)
void Library::run() {
    std::cout << "Welcome to the Library Management System!" << std::endl;
    // In a real application, you would have a menu loop here.
    // For now, this is just a placeholder.
    showMenu();
}

// Private method to show the main menu
void Library::showMenu() {
    std::cout << "\n--- Library Menu ---\n";
    std::cout << "This is a placeholder for the menu.\n";
    std::cout << "Functionality is handled by the web server.\n";
}

// Method to add a member (used by the server)
void Library::addMember(std::string name, std::string id, std::string type) {
    // Check if member already exists
    if (findMemberByID(id)) {
        std::cout << "Member with ID " << id << " already exists." << std::endl;
        // In a real app, you might throw an exception here
        return;
    }
    
    if (type == "student") {
        members.push_back(new Student(name, id));
        std::cout << "Student '" << name << "' added." << std::endl;
    } else if (type == "teacher") {
        members.push_back(new Teacher(name, id));
        std::cout << "Teacher '" << name << "' added." << std::endl;
    } else {
        std::cout << "Unknown member type: " << type << std::endl;
    }
}

// Helper to find a member by their ID
Member* Library::findMemberByID(std::string id) {
    for (Member* member : members) {
        if (member->getMemberID() == id) {
            return member;
        }
    }
    return nullptr; // Return null if not found
}

// --- Placeholder Implementations for other functions ---
// You can fill these in with your application's logic later.

void Library::addMember() {
    std::cout << "Function 'addMember' (console version) is not implemented.\n";
}

void Library::addBook() {
    std::cout << "Function 'addBook' is not implemented.\n";
}

void Library::loanBook() {
    std::cout << "Function 'loanBook' is not implemented.\n";
}

void Library::returnBook() {
    std::cout << "Function 'returnBook' is not implemented.\n";
}

void Library::calculateFee() {
    std::cout << "Function 'calculateFee' is not implemented.\n";
}

void Library::viewCatalog() {
    std::cout << "Function 'viewCatalog' is not implemented.\n";
}

Loan* Library::findActiveLoan(Book* book) {
    std::cout << "Function 'findActiveLoan' is not implemented.\n";
    return nullptr;
}