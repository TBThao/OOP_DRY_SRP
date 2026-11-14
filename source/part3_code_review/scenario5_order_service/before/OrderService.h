#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class OrderService {
    std::vector<std::string> fakeDatabaseTable;
public:
    void placeOrder(const std::string& customerEmail, const std::vector<long>& prices) {
        if (customerEmail.empty() || customerEmail.find("@") == std::string::npos) 
            throw std::invalid_argument("email");
        if (prices.empty()) 
            throw std::invalid_argument("empty order");

        long total = 0;
        for (long p : prices) total += p;
        if (total > 1000000) total = total * 95 / 100;

        fakeDatabaseTable.push_back("INSERT INTO orders(email,total) VALUES('" + customerEmail + "'," + std::to_string(total) + ")");

        std::cout << "[SMTP smtp.example.com:587] to=" << customerEmail
                  << " subject=Order confirmed total=" << total << "\n";
    }

    std::vector<std::string> table() const { return fakeDatabaseTable; }
};