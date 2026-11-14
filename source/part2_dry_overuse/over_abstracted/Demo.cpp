#include <iostream>
#include "LineFormatter.h"

int main() {
    std::cout << LineFormatter::format(LineFormatter::Mode::INVOICE,
                 "Notebook", 3, 25000, false, true, false, true, 12) << "\n";
    std::cout << LineFormatter::format(LineFormatter::Mode::GRADE,
                 "Algorithms", 3, 8.7, false, false, true, true, 12) << "\n";
    return 0;
}