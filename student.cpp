#include "Student.h"

double Student::calculateLateFee(int daysLate) {
    return daysLate * 0.50;
}