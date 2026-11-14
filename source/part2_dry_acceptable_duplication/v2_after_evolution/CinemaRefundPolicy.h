#pragma once
class CinemaRefundPolicy {
public:
    int refundPercent(long hoursBeforeShow, bool promoTicket) {
        if (promoTicket || hoursBeforeShow < 0) return 0;
        return hoursBeforeShow >= 24 ? 100 : 50;
    }
};