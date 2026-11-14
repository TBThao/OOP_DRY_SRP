#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Order.h"
#include "OrderRepository.h"
#include "NotificationSender.h"
#include "OrderService.h"

class FakeOrderRepository : public OrderRepository {
public:
    std::vector<std::string> saved;
    void save(const Order& order) override {
        saved.push_back(order.customerEmail() + ":" + std::to_string(order.total()));
    }
};

class FakeNotificationSender : public NotificationSender {
public:
    void orderConfirmed(const std::string& email, long total) override {
        std::cout << "[fake mail] to=" << email << " total=" << total << "\n";
    }
};

int main() {
    auto fakeRepo = std::make_shared<FakeOrderRepository>();
    auto fakeMail = std::make_shared<FakeNotificationSender>();

    OrderService s(fakeRepo, fakeMail);
    s.placeOrder(Order("an@example.com", {600000, 600000}));
    
    std::cout << "[";
    for(size_t i = 0; i < fakeRepo->saved.size(); ++i) {
        std::cout << (i > 0 ? ", " : "") << fakeRepo->saved[i];
    }
    std::cout << "]\n";
    return 0;
}