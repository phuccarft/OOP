#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Member.h"
#include "Book.h"
#include "Loan.h"
#include "Catalog.h" 

class Library {
private:
    // Internal data remains private
    Catalog catalog;            
    std::vector<Member*> members;
    std::vector<Loan> loans;    

    // Internal helper functions can remain private
    Member* findMemberByID(std::string id);
    Loan* findActiveLoan(Book* book); 

public: // This is the public interface for your class
    Library() = default; 
    ~Library();          

    void run(); // For the console app
    
    // **MOVED HERE:** This function now needs to be public so server_main.cpp can call it.
    void addMember(std::string name, std::string id, std::string type); 

private: // These are only used internally by the class
    void showMenu();
    void addMember(); // Overloaded version for console, can stay private if only called by run()
    void addBook();
    void loanBook();    
    void returnBook();  
    void calculateFee();
    void viewCatalog(); 
};

#endif // LIBRARY_H