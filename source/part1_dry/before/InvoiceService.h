#pragma once
#include <vector>

class InvoiceService {
public:
    long finalTotal(const std::vector<long>& itemPrices, bool vip) {
        long subtotal = 0;
        for (long p : itemPrices) subtotal += p;
        // BẢN SAO #2: marketing đã đổi ngưỡng lên 700.000, nhưng chỉ sửa ở đây
        long shipping = subtotal >= 700000 ? 0 : 30000;
        // BẢN SAO #2 của chính sách VIP
        long discount = vip ? subtotal * 10 / 100 : 0;
        return subtotal - discount + shipping;
    }
};