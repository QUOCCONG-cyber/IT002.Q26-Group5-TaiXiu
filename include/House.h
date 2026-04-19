#pragma once
#include "Actor.h"

class House : public Actor {
public:
    House(double commissionRate, double minBet, double maxBet);

    double getCommissionRate() const;
    double getMinBet()         const;
    double getMaxBet()         const;
    double limitBet(double amount) const;

private:
    double dCommissionRate;
    double dMinBet;
    double dMaxBet;
};
