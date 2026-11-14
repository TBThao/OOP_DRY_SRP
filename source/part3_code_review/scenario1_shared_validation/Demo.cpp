#include <iostream>
#include "CreateOrder.h"
#include "UpdateOrder.h"

int main() {
    std::cout << CreateOrder().execute("An", "an@example.com", 25) << "\n";
    try {
        UpdateOrder().execute("Binh", "binh@example.com", 16);
    } catch (const std::invalid_argument& ex) {
        std::cout << "rejected consistently: " << ex.what() << "\n";
    }
    return 0;
}