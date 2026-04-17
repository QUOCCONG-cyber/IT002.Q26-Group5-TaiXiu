#include "Dice.h"
/*tạo xúc xắc*/
Dice::Dice() {
    std::random_device rd;
    rng.seed(rd());
}
/*lắc xúc xắc*/
int Dice::roll() {
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng); 
}
