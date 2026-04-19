#include "../include/House.h"

/*
 * @brief Khởi tạo House với các thông số luật chơi
 * @param commissionRate Tỉ lệ tiền xâu (ví dụ: 0.05 = 5%)
 * @param minBet         Mức cược tối thiểu
 * @param maxBet         Mức cược tối đa
 */
House::House(double commissionRate, double minBet, double maxBet)
    : dCommissionRate(commissionRate)
    , dMinBet(minBet)
    , dMaxBet(maxBet)
{
    dBalance = 0.0;
}

double House::getCommissionRate() const { return dCommissionRate; }
double House::getMinBet()         const { return dMinBet; }
double House::getMaxBet()         const { return dMaxBet; }

/*
 * @brief Giới hạn số tiền cược trong khoảng [dMinBet, dMaxBet]
 * @param amount Số tiền muốn cược
 * @return Số tiền hợp lệ
 */
double House::limitBet(double amount) const {
    if (amount < dMinBet) return dMinBet;
    if (amount > dMaxBet) return dMaxBet;
    return amount;
}
