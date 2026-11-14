#pragma once
class HotelRefundPolicy {
public:
    int refundPercent(long hoursBeforeCheckIn, bool peakSeason, bool nonRefundableRate) {
        if (nonRefundableRate) return 0;
        long fullRefundHours = peakSeason ? 24 * 7 : 24;
        if (hoursBeforeCheckIn >= fullRefundHours) return 100;
        return hoursBeforeCheckIn >= 24 ? 50 : 0;
    }
};