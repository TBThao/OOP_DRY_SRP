#pragma once
#include <memory>
#include "Order.h"
#include "OrderRepository.h"
#include "NotificationSender.h"

class OrderService {
    std::shared_ptr<OrderRepository> repository;
    std::shared_ptr<NotificationSender> notifier;
public:
    OrderService(std::shared_ptr<OrderRepository> repository, std::shared_ptr<NotificationSender> notifier)
        : repository(repository), notifier(notifier) {}

    void placeOrder(Order order) {
        order.validate();
        repository->save(order);
        notifier->orderConfirmed(order.customerEmail(), order.total());
    }
};