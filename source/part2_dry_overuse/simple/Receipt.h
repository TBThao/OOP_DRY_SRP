#pragma once
#include <string>
#include <iomanip>
#include <sstream>

class Receipt {
public:
    static std::string line(const std::string& item, int quantity, long unitPrice) {
        std::ostringstream oss;
        oss << std::left << std::setw(12) << item 
            << " x" << quantity << "  " << (quantity * unitPrice) << " VND";
        return oss.str();
    }
};