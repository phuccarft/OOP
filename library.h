#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Member.h" 
#include "Book.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;    
    std::vector<Member*> members;
    std::vector<Loan> loans;    

    
    Member* findMemberByID(std::string id);
    Book* findBookByIsbn(std::string isbn);
    
    Loan* findActiveLoan(Book* book); 

public:
    
    Library() = default; 
    ~Library();          

    
    void run();

private:
    
    void showMenu();
    void addMember();
    //
    void addMember(std::string name, std::string id, std::string type); 
    void addBook();
    void loanBook();    
    void returnBook();  
    void calculateFee();
};

#endif 
