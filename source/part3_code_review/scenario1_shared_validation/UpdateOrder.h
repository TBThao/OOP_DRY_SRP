#pragma once
#include <string>
#include "CustomerValidator.h"

class UpdateOrder {
public:
    std::string execute(const std::string& name, const std::string& email, int age) {
        CustomerValidator::validate(name, email, age);
        return "order updated for " + name;
    }
};