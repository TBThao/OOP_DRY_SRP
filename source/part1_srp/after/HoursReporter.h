#pragma once
#include <string>
#include <algorithm>
#include "Employee.h"

class HoursReporter {
    static constexpr int REGULAR_HOURS_FOR_REPORT = 40;
public:
    std::string report(const Employee& e) {
        int regular = std::min(e.hoursWorked, static_cast<int>(REGULAR_HOURS_FOR_REPORT));
        return e.name + ": " + std::to_string(regular) + "h regular, " + 
               std::to_string(e.hoursWorked - regular) + "h overtime";
    }
};