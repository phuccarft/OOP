#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Member.h"
#include <chrono> // For handling dates
#include <string>
#include <sstream> // For formatting dates
#include <iomanip> // For formatting dates

class Loan {
public:
    Book* book;     // Pointer to the loaned book
    Member* member; // Pointer to the borrowing member
    std::chrono::system_clock::time_point borrowDate;
    std::chrono::system_clock::time_point dueDate;
    bool isReturned;

    // Constructor to create a new loan
    Loan(Book* b, Member* m) 
        : book(b), member(m), isReturned(false) {
        
        borrowDate = std::chrono::system_clock::now();
        
        // Set due date 14 days from now
        using namespace std::chrono_literals; // Allows using 24h
        dueDate = borrowDate + (14 * 24h); 

        // Update the book's status
        book->setAvailable(false);
    }

    // Mark the loan as complete and make the book available
    void returnBook() {
        isReturned = true;
        book->setAvailable(true);
    }

    // Check if the loan is overdue
    int getDaysLate() const {
        if (isReturned) return 0; // Not late if already returned

        auto now = std::chrono::system_clock::now();
        if (now > dueDate) {
            // Calculate the difference in days
            auto diff = std::chrono::duration_cast<std::chrono::hours>(now - dueDate);
            return (diff.count() / 24) + 1; // +1 to count partial days
        }
        return 0; // Not overdue yet
    }
};

#endif // LOAN_H
