#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isLoaned;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(title), author(author), isbn(isbn), isLoaned(false) {}
    std::string getTitle() const { return title; }
    std::string getIsbn() const { return isbn; }
    bool getIsLoaned() const { return isLoaned; }
    void setLoaned(bool status) { isLoaned = status; }
};