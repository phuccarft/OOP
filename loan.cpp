#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
class Loan {
private:
    Member* member;
    Book* book;
    Loan* l;
    time_t loanDate;
    time_t dueDate;
    bool returned;

public:
    Loan(Member* m, Book* b) : member(m), book(b), returned(false) {
        loanDate = time(nullptr);
        dueDate = loanDate + 7; // 7 days
    }

    Member* getMember() const { return member; }
    Book* getBook() const { return book; }

    void returnBook() {
        returned = true;
        book->setAvailable(true);
    }
    bool isReturned() const { return returned; }

    void display() const {
        cout << "Loan: " << book->getTitle() << " borrowed by " << member->getName()
             << " (" << member->getType() << ") - Status: "
             << (returned ? "Returned" : "On Loan") << endl;
    }
};
