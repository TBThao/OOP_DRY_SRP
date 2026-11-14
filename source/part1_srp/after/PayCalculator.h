#pragma once
#include <algorithm>
#include "Employee.h"

class PayCalculator {
    static constexpr int REGULAR_HOURS = 40;
    static constexpr double OVERTIME_MULTIPLIER = 1.5;
public:
    double calculatePay(const Employee& e) {
        int regular = std::min(e.hoursWorked, static_cast<int>(REGULAR_HOURS));
        int overtime = e.hoursWorked - regular;
        return regular * e.hourlyRate + overtime * e.hourlyRate * OVERTIME_MULTIPLIER;
    }
};