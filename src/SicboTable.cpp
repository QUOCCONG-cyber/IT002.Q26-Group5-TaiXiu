#include "SicboTable.h"
#include "SicBoTable.h"

SicBoTable::SicBoTable() : totalScore(0) {}

void SicBoTable::shake() {
    totalScore = 0;
    for (int i = 0; i < 3; ++i) {
        dices[i].roll(); 
        totalScore += dices[i].getFaceValue();
    }
}

int SicBoTable::getTotalScore() const {
    return totalScore;
}

std::string SicBoTable::getResultString() const {
    if (totalScore >= 3 && totalScore <= 10) {
        return "XIU";
    }
    else if (totalScore >= 11 && totalScore <= 18) {
        return "TAI";
    }
    return "UNKNOWN";
}
