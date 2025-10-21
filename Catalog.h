#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <string>
#include <iostream>
#include "Book.h"

class Catalog {
private:
    std::vector<Book*> books;

public:
    // Destructor to clean up allocated memory
    ~Catalog() {
        for (Book* book : books) {
            delete book;
        }
    }

    // Method to add a book (for testing)
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Method to find a book
    Book* findBookByTitle(const std::string& title) {
        for (Book* book : books) {
            if (book->getTitle() == title) {
                return book;
            }
        }
        return nullptr; // Not found
    }
};

#endif // CATALOG_H