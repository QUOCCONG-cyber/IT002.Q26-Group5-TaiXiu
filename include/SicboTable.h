
#ifndef SICBOTABLE_H
#define SICBOTABLE_H

#include "Dice.h"
#include <string>

class SicBoTable {
private:
    Dice dices[3]; 
    int totalScore;

public:
    SicBoTable();

    void shake();

    int getTotalScore() const;

    std::string getResultString() const;
};

#endif
