#include "Table.h"
#include <iostream>
/*tạo bàn có 3 xúc xắc*/
Table::Table(const House& h, const Player& p)
    : house(h), player(p) {
    dices = std::vector<Dice>(3);
}
/*tính kết quả*/
void Table::play() {
    int totalScore = 0;

    for (int i = 0; i < 3; ++i) {
        int face = dices[i].roll();
        totalScore += face;
    }

}