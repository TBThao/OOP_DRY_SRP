#include <iostream>
#include "CinemaRefundPolicy.h"
#include "HotelRefundPolicy.h"

int main() {
    std::cout << "Cinema, 30h before : " << CinemaRefundPolicy().refundPercent(30) << "%\n";
    std::cout << "Hotel , 30h before : " << HotelRefundPolicy().refundPercent(30) << "%\n";
    std::cout << "Cinema, 10h before : " << CinemaRefundPolicy().refundPercent(10) << "%\n";
    std::cout << "Hotel , 10h before : " << HotelRefundPolicy().refundPercent(10) << "%\n";
    return 0;
}