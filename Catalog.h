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
    ~Catalog() {
        for (Book* book : books) {
            delete book;
        }
    }
    void addBook(Book* book) {
        books.push_back(book);
    }
    Book* findBookByTitle(const std::string& title) {
        for (Book* book : books) {
            if (book->getTitle() == title) {
                return book;
            }
        }
        return nullptr;
    }
};

#endif
