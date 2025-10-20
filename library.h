#pragma once
#include "Book.h"
#include "Member.h"
#include <vector>

class Library {
private:
    std::vector<Member*> members;
    std::vector<Book> books;
    void showMenu();
    void addMember();
    void addBook();
    void loanBook();
    void returnBook();
    void calculateFee();
    Member* findMemberByID(std::string id);
    Book* findBookByIsbn(std::string isbn);

public:
    void run();
    ~Library();
    void addMember(std::string name, std::string id, std::string type);
};