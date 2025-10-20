#pragma once
#include "Member.h"

class Student : public Member {
public:
    Student(std::string name, std::string memberID)
        : Member(name, memberID) {}
    double calculateLateFee(int daysLate) override;
};