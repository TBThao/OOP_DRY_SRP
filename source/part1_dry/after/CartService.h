#pragma once
#include <vector>
#include "PricingPolicy.h"

class CartService {
public:
    long previewTotal(const std::vector<long>& itemPrices, bool vip) {
        return PricingPolicy::total(itemPrices, vip);
    }
};