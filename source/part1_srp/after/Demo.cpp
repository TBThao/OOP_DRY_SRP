#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>
#include "Employee.h"
#include "PayCalculator.h"
#include "HoursReporter.h"
#include "EmployeeRepository.h"

int main() {
    Employee e{"An", 100000, 46};
    std::cout << "Pay    : " << std::fixed << std::setprecision(0) << PayCalculator().calculatePay(e) << "\n";
    std::cout << "Report : " << HoursReporter().report(e) << "\n";
    
    std::string tmp = "employees_tmp.csv";
    std::remove(tmp.c_str());   // mỗi lần chạy bắt đầu từ file trống
    EmployeeRepository(tmp).save(e);
    
    std::ifstream in(tmp);
    std::string savedLine;
    if (std::getline(in, savedLine)) {
        std::cout << "Saved  : " << savedLine << "\n";
    }
    in.close();
    std::remove(tmp.c_str());
    return 0;
}