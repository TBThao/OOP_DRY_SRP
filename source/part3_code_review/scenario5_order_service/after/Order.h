#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class Order {
    std::string customerEmail_;
    std::vector<long> prices_;
public:
    Order(const std::string& customerEmail, const std::vector<long>& prices)
        : customerEmail_(customerEmail), prices_(prices) {}

    std::string customerEmail() const { return customerEmail_; }

    void validate() const {
        if (customerEmail_.empty() || customerEmail_.find("@") == std::string::npos) 
            throw std::invalid_argument("email");
        if (prices_.empty()) 
            throw std::invalid_argument("empty order");
    }

    long total() const {
        long total = 0;
        for (long p : prices_) total += p;
        return total > 1000000 ? total * 95 / 100 : total;
    }
};