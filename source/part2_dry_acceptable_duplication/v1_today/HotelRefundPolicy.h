#pragma once
class HotelRefundPolicy {
public:
    int refundPercent(long hoursBeforeCheckIn) {
        return hoursBeforeCheckIn >= 24 ? 100 : 50;
    }
};