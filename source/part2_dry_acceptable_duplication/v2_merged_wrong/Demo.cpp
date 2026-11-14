#include <iostream>
#include "RefundPolicy.h"

int main() {
    RefundPolicy p;
    std::cout << p.refundPercent(RefundPolicy::Kind::CINEMA, 30, true, false, false) << "%\n";
    std::cout << p.refundPercent(RefundPolicy::Kind::HOTEL, 72, false, true, false) << "%\n";
    return 0;
}