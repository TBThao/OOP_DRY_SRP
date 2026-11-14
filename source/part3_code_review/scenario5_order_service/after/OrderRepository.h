#pragma once
#include "Order.h"

struct OrderRepository {
    virtual void save(const Order& order) = 0;
    virtual ~OrderRepository() = default;
};