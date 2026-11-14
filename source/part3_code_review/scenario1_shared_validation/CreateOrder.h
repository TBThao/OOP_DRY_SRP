#pragma once
#include <string>
#include "CustomerValidator.h"

class CreateOrder {
public:
    std::string execute(const std::string& name, const std::string& email, int age) {
        CustomerValidator::validate(name, email, age);
        return "order created for " + name;
    }
};