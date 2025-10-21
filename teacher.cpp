#include "Teacher.h"

// Teachers might have a different fee structure
double Teacher::calculateLateFee(int daysLate) {
    return daysLate * 0.25; // Example: $0.25 per day
}