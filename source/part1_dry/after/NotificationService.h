#pragma once
#include <string>
#include "PricingPolicy.h"

class NotificationService {
public:
    std::string shippingBanner() {
        return PricingPolicy::shippingBanner();
    }
};