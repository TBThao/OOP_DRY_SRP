#pragma once
#include <string>
#include <stdexcept>

class CustomerValidator {
    CustomerValidator() = delete;
public:
    static void validate(const std::string& name, const std::string& email, int age) {
        if (name.empty()) throw std::invalid_argument("name is required");
        if (email.find("@") == std::string::npos) throw std::invalid_argument("email is invalid");
        if (age < 18) throw std::invalid_argument("customer must be 18+");
    }
};