#include <iostream>
#include "Receipt.h"
#include "Transcript.h"

int main() {
    std::cout << Receipt::line("Notebook", 3, 25000) << "\n";
    std::cout << Transcript::line("Algorithms", 3, 8.7) << "\n";
    return 0;
}