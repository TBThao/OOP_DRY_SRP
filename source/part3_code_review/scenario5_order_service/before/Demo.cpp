#include <iostream>
#include <vector>
#include "OrderService.h"

int main() {
    OrderService s;
    s.placeOrder("an@example.com", {600000, 600000});
    
    std::cout << "[";
    const auto& t = s.table();
    for(size_t i = 0; i < t.size(); ++i) {
        std::cout << (i > 0 ? ", " : "") << t[i];
    }
    std::cout << "]\n";
    return 0;
}