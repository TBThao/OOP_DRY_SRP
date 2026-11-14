#pragma once
#include <string>
#include <fstream>
#include "Employee.h"

class EmployeeRepository {
    std::string file;
public:
    EmployeeRepository(const std::string& file) : file(file) {}
    void save(const Employee& e) {
        std::ofstream out(file, std::ios_base::app);
        if(out.is_open()) {
            out << e.name << "," << e.hourlyRate << "," << e.hoursWorked << "\n";
        }
    }
};