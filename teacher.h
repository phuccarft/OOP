#pragma once
#include "Member.h"

class Teacher : public Member {
public:
    Teacher(std::string name, std::string memberID)
        : Member(name, memberID) {}
    
    // Override the virtual function from Member
    double calculateLateFee(int daysLate) override;
};