#pragma once
#include <vector>

class CartService {
public:
    long previewTotal(const std::vector<long>& itemPrices, bool vip) {
        long subtotal = 0;
        for (long p : itemPrices) subtotal += p;
        // BẢN SAO #1: miễn phí vận chuyển từ 500.000 VND
        long shipping = subtotal >= 500000 ? 0 : 30000;
        // BẢN SAO #1: giảm giá VIP 10%
        long discount = vip ? subtotal * 10 / 100 : 0;
        return subtotal - discount + shipping;
    }
};