#include "dice.h"

Dice::Dice() {
        std::random_device rd;
    rng.seed(rd());

    Value = 1;
}

void Dice::roll() {
    std::uniform_int_distribution<int> dist(1, 6);

    Value = dist(rng);
}

int Dice::getValue() const {
    return Value;
}