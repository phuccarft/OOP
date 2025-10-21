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
    
    Catalog catalog;            
    
    std::vector<Member*> members;
    std::vector<Loan> loans;    

    
    Member* findMemberByID(std::string id);
    
    Loan* findActiveLoan(Book* book); 

public:
    Library() = default; 
    ~Library();          

    void run();

private:
    void showMenu();
    void addMember();
    void addMember(std::string name, std::string id, std::string type); 
    void addBook();
    void loanBook();    
    void returnBook();  
    void calculateFee();
    
    
    void viewCatalog(); 
};

#endif // LIBRARY_H
