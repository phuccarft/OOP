#pragma once
#include <string>
#include <vector>
class Member {
protected:
    std::string name;
    std::string memberID;

public:
    Member(std::string name, std::string memberID)
        : name(name), memberID(memberID) {}
    virtual ~Member() {}
    virtual double calculateLateFee(int daysLate) = 0;
    std::string getName() const { return name; }
    std::string getMemberID() const { return memberID; }
};