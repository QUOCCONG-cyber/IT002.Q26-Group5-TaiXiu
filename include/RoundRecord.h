#pragma once
#include "ABettingStrategy.h"
struct RoundRecord {
    Bet       bet;              /* Cược đặt trong ván (cửa Tài/Xỉu và số tiền) */
    BetResult result;           /* Kết quả ván: Win hoặc Lose */
    double    dCurrentBankroll; /* Số dư sau khi ván kết thúc */

    RoundRecord(Bet b, BetResult r, double bankroll)
        : bet(b), result(r), dCurrentBankroll(bankroll) {}
};
