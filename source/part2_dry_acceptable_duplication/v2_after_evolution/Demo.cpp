#include <iostream>
#include "CinemaRefundPolicy.h"
#include "HotelRefundPolicy.h"

int main() {
    std::cout << "Cinema promo ticket       : " << CinemaRefundPolicy().refundPercent(30, true) << "%\n";
    std::cout << "Cinema normal, 10h before : " << CinemaRefundPolicy().refundPercent(10, false) << "%\n";
    std::cout << "Hotel peak, 3 days before : " << HotelRefundPolicy().refundPercent(72, true, false) << "%\n";
    std::cout << "Hotel off-peak, 30h before: " << HotelRefundPolicy().refundPercent(30, false, false) << "%\n";
    return 0;
}