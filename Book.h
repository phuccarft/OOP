#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    bool available;

public:
    // Constructor
    Book(std::string t, std::string a) : title(t), author(a), available(true) {}

    // Method to update availability
    void setAvailable(bool status) {
        available = status;
    }

    // Accessor methods
    std::string getTitle() const {
        return title;
    }

    bool isAvailable() const {
        return available;
    }
};

#endif // BOOK_H