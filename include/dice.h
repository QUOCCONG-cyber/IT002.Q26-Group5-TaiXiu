#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
private:
    int Value;
    std::mt19937 rng; 

public:
    Dice();
    void roll();

    int getValue() const;
};

#endif 

