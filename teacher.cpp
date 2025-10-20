#include "Teacher.h"

double Teacher::calculateLateFee(int daysLate) {
    return daysLate * 0.25;
}