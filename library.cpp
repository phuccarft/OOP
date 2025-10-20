#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <limits>

void Library::run() {
    int choice = 0;
    while (choice != 6) {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le. Vui long nhap so.\n";
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: addMember(); break;
            case 2: addBook(); break;
            case 3: loanBook(); break; 
            case 4: returnBook(); break; 
            case 5: calculateFee(); break;
            case 6: std::cout << "Tam biet!\n"; break;
            default: std::cout << "Lua chon khong hop le. Thu lai.\n";
        }
        std::cout << "\n";
    }
}

void Library::showMenu() {
    std::cout << "--- HE THONG QUAN LY THU VIEN ---\n";
    std::cout << "1. Them thanh vien (Student/Teacher)\n";
    std::cout << "2. Them sach moi\n";
    std::cout << "3. Muon sach\n";
    std::cout << "4. Tra sach\n";
    std::cout << "5. Tinh phi tre han\n";
    std::cout << "6. Thoat\n";
    std::cout << "Nhap lua chon cua ban: ";
}

void Library::addMember() {
    std::string name, id, type;
    std::cout << "Ban muon them (S)tudent hay (T)eacher? ";
    std::getline(std::cin, type);

    std::cout << "Nhap ten: ";
    std::getline(std::cin, name);
    std::cout << "Nhap ID thanh vien: ";
    std::getline(std::cin, id);

    if (type == "S" || type == "s") {
        members.push_back(new Student(name, id));
        std::cout << "Da them sinh vien: " << name << "\n";
    } else if (type == "T" || type == "t") {
        members.push_back(new Teacher(name, id));
        std::cout << "Da them giao vien: " << name << "\n";
    } else {
        std::cout << "Loai thanh vien khong hop le.\n";
    }
}
void Library::addMember(std::string name, std::string id, std::string type) {
    if (type == "student") {
        members.push_back(new Student(name, id));
        std::cout << "[Server Log] Da them Student: " << name << std::endl;
    } else if (type == "teacher") {
        members.push_back(new Teacher(name, id));
        std::cout << "[Server Log] Da them Teacher: " << name << std::endl;
    } else {
        std::cout << "[Server Log] LOI: Loai thanh vien khong hop le" << std::endl;
    }
}

void Library::addBook() {
    std::string title, author, isbn;
    std::cout << "Nhap tieu de sach: ";
    std::getline(std::cin, title);
    std::cout << "Nhap tac gia: ";
    std::getline(std::cin, author);
    std::cout << "Nhap ma ISBN: ";
    std::getline(std::cin, isbn);

    books.push_back(Book(title, author, isbn));
    std::cout << "Da them sach: " << title << "\n";
}

void Library::calculateFee() {
    std::cout << "--- Day la vi du ve Tinh Da Hinh (Polymorphism) ---\n";
    std::string id;
    int daysLate;

    std::cout << "Nhap ID thanh vien: ";
    std::getline(std::cin, id);

    Member* member = findMemberByID(id);
    if (member == nullptr) {
        std::cout << "Khong tim thay thanh vien voi ID: " << id << "\n";
        std::cout << "--- Demo tinh phi ---\n";
        Member* demoStudent = new Student("Demo SV", "S1");
        Member* demoTeacher = new Teacher("Demo GV", "T1");

        std::cout << "Phi tre 10 ngay cho Student: $" 
                  << demoStudent->calculateLateFee(10) << "\n";
        std::cout << "Phi tre 10 ngay cho Teacher: $" 
                  << demoTeacher->calculateLateFee(10) << "\n"; 

        delete demoStudent;
        delete demoTeacher;
        
        return;
    }

    std::cout << "Thanh vien tim thay: " << member->getName() << "\n";
    std::cout << "Nhap so ngay tre han: ";
    std::cin >> daysLate;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    double fee = member->calculateLateFee(daysLate);
    std::cout << "Tong phi tre han cho " << member->getName() << " la: $" << fee << "\n";
}

Member* Library::findMemberByID(std::string id) {
    for (Member* m : members) {
        if (m->getMemberID() == id) {
            return m;
        }
    }
    return nullptr;
}

Book* Library::findBookByIsbn(std::string isbn) {
    for (auto& book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

void Library::loanBook() {
    std::cout << "Chuc nang Muon Sach chua duoc cai dat.\n";
}

void Library::returnBook() {
    std::cout << "Chuc nang Tra Sach chua duoc cai dat.\n";
}

Library::~Library() {
    for (Member* member : members) {
        delete member;
    }
}