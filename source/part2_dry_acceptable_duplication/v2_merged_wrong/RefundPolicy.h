#pragma once

class RefundPolicy {
public:
    enum class Kind { CINEMA, HOTEL };

    int refundPercent(Kind kind, long hoursBefore,
                      bool promoTicket, bool peakSeason, bool nonRefundableRate) {
        if (kind == Kind::CINEMA) {
            if (promoTicket || hoursBefore < 0) return 0;
            return hoursBefore >= 24 ? 100 : 50;
        } else {
            if (nonRefundableRate) return 0;
            long full = peakSeason ? 24 * 7 : 24;
            if (hoursBefore >= full) return 100;
            return hoursBefore >= 24 ? 50 : 0;
        }
    }
};