#include "Catalog.h"
#include <iostream>

/**
 * Adds a new Book object to the catalog.
 */
void Catalog::addBook(const Book& book) {
    books.push_back(book);
    // The Catalog itself shouldn't print, but the Library can.
    // We'll let the Library handle the "std::cout"
}

/**
 * Finds a book by its ISBN.
 */
Book* Catalog::findBookByIsbn(const std::string& isbn) {
    for (auto& book : books) { // Use auto& to get a reference
        if (book.getIsbn() == isbn) {
            return &book; // Return the address of the book
        }
    }
    return nullptr; // Not found
}

/**
 * Prints details for all books in the catalog.
 */
void Catalog::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "The catalog is currently empty." << std::endl;
        return;
    }

    std::cout << "--- Library Catalog ---" << std::endl;
    for (const Book& book : books) {
        // We call the book's to_string() helper method
        std::cout << book.to_string() << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}
