#pragma once
#include "Member.h"

class Teacher : public Member {
public:
    Teacher(std::string name, std::string memberID)
        : Member(name, memberID) {}
    double calculateLateFee(int daysLate) override;
};