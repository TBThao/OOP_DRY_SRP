#pragma once
#include <string>

class NotificationService {
public:
    std::string shippingBanner() {
        // BẢN SAO #3: cùng một tri thức nhưng nằm trong chuỗi văn bản
        return "Free shipping for orders from 500000 VND, VIP members get 10% off";
    }
};