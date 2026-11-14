#pragma once
#include <vector>
#include "PricingPolicy.h"

class InvoiceService {
public:
    long finalTotal(const std::vector<long>& itemPrices, bool vip) {
        return PricingPolicy::total(itemPrices, vip);
    }
};