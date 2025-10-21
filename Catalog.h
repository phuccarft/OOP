#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <string>
#include "Book.h" // Needs to know what a Book is

class Catalog {
private:
    std::vector<Book> books; // The list of books lives here now

public:
    Catalog() = default; // Default constructor

    // --- Public Methods ---

    /**
     * Adds a new Book object to the catalog.
     */
    void addBook(const Book& book);

    /**
     * Finds a book by its ISBN.
     * Returns a pointer to the book in the catalog, or 'nullptr' if not found.
     */
    Book* findBookByIsbn(const std::string& isbn);

    /**
     * Prints details for all books in the catalog.
     * (This is a new helper method that makes sense for a catalog)
     */
    void displayAllBooks() const;
};

#endif // CATALOG_H
