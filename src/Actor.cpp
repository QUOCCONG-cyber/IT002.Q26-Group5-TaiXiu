#include "../include/Actor.h"

double Actor::getBalance() const { return this->dBalance; }
void Actor::setBalance(double const &amount) { this->dBalance = amount; }
void Actor::updateBalance(double const &amount) { this->dBalance += amount; }
