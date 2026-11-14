#pragma once
class CinemaRefundPolicy {
public:
    int refundPercent(long hoursBeforeShow) {
        return hoursBeforeShow >= 24 ? 100 : 50;
    }
};