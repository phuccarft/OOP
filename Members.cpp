#include <iostream>
#include <string>

class Member {
protected: 
    std::string name;
    std::string member_id;

public:
    Member(const std::string& name, const std::string& member_id)
        : name(name), member_id(member_id) {
    }
    virtual ~Member() {}
    virtual void display_info() const {
        std::cout << "--- Thong tin Thanh vien ---" << std::endl;
        std::cout << "Ten: " << this->name << std::endl;
        std::cout << "Ma Thanh vien: " << this->member_id << std::endl;
    }
};

class Student : public Member {
private:
    std::string student_id;

public:
    Student(const std::string& name, const std::string& member_id, const std::string& student_id)
        : Member(name, member_id), student_id(student_id) {}
    void display_info() const override {
        Member::display_info(); 
        std::cout << "Ma Sinh vien: " << this->student_id << std::endl;
    }
};

class Teacher : public Member {
private:
    std::string department;

public:
    Teacher(const std::string& name, const std::string& member_id, const std::string& department)
        : Member(name, member_id), department(department) {}
    void display_info() const override {
        Member::display_info();
        std::cout << "Khoa: " << this->department << std::endl;
    }
}; 

int main() {
    std::cout << "Tao doi tuong Sinh vien:" << std::endl;
    Student student_a("Nguyen Van A", "M123", "S56789");
    student_a.display_info();

    std::cout << "\n----------------------\n" << std::endl;
    std::cout << "Tao doi tuong Giao vien:" << std::endl;
    Teacher teacher_b("Tran Thi B", "M124", "Cong nghe thong tin");
    
    teacher_b.display_info();

    std::cout << "\n----------------------\n" << std::endl;
    std::cout << "Tao doi tuong Thanh vien (chung):" << std::endl;
    Member member_c("Le C", "M125");
    member_c.display_info();

    return 0;
}
