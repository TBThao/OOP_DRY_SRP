#pragma once
#include <string>

struct NotificationSender {
    virtual void orderConfirmed(const std::string& email, long total) = 0;
    virtual ~NotificationSender() = default;
};