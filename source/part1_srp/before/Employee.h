#pragma once
#include <string>
#include <fstream>
#include <algorithm>

class Employee {
    std::string name;
    double hourlyRate;
    int hoursWorked;
    
    // Hàm dùng chung => nếu Kế toán đổi cách tính giờ chuẩn, báo cáo của Nhân sự sai theo
    int regularHours() const {
        return std::min(hoursWorked, 40);
    }
public:
    Employee(const std::string& name, double hourlyRate, int hoursWorked) 
        : name(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    // Actor 1: Kế toán
    double calculatePay() const {
        int regular = regularHours();
        int overtime = hoursWorked - regular;
        return regular * hourlyRate + overtime * hourlyRate * 1.5;
    }
    // Actor 2: Nhân sự
    std::string reportHours() const {
        return name + ": " + std::to_string(regularHours()) + "h regular, "
             + std::to_string(hoursWorked - regularHours()) + "h overtime";
    }
    // Actor 3: IT / DBA
    void save(const std::string& file) const {
        std::ofstream out(file, std::ios_base::app);
        if(out.is_open()) {
            out << name << "," << hourlyRate << "," << hoursWorked << "\n";
        }
    }
};