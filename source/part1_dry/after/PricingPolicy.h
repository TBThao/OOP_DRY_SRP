#pragma once
#include <vector>
#include <string>

class PricingPolicy {
public:
    static constexpr long FREE_SHIPPING_THRESHOLD = 700000;
    static constexpr long SHIPPING_FEE = 30000;
    static constexpr int VIP_DISCOUNT_PERCENT = 10;

    PricingPolicy() = delete;

    static long subtotal(const std::vector<long>& itemPrices) {
        long s = 0;
        for (long p : itemPrices) s += p;
        return s;
    }

    static long shippingFee(long subtotal) {
        return subtotal >= FREE_SHIPPING_THRESHOLD ? 0 : SHIPPING_FEE;
    }

    static long vipDiscount(long subtotal, bool vip) {
        return vip ? subtotal * VIP_DISCOUNT_PERCENT / 100 : 0;
    }

    static long total(const std::vector<long>& itemPrices, bool vip) {
        long sub = subtotal(itemPrices);
        return sub - vipDiscount(sub, vip) + shippingFee(sub);
    }

    static std::string shippingBanner() {
        return "Free shipping for orders from " + std::to_string(FREE_SHIPPING_THRESHOLD) +
               " VND, VIP members get " + std::to_string(VIP_DISCOUNT_PERCENT) + "% off";
    }
};