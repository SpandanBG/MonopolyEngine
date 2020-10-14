#define DEBUG

#include <utility>

#include "player.h"

#include "assets/playerPeices.h"
#include "assets/contants.h"

#include "models/die/die.h"

Player::Player(PeiceTypes peice, Die& die) : peiceType(peice), die(die) {
    money = INITIAL_PLAYER_MONEY;
    currentBoardPosition = INITIAL_PLAYER_POSITION;
    turns = NO_TURNS;
}

std::pair<int, int> Player::throwDice() {
    return std::pair<int, int>(die.throwDie(), die.throwDie());
}

void Player::creditMoney(int creditAmount) {
    money += creditAmount;
}

void Player::debitMoney(int debitAmount) {
    money -= debitAmount;
}

int Player::getPosition() {
    return currentBoardPosition;
}

void Player::setPosition(int newPosition) {
    currentBoardPosition = newPosition;
}

bool Player::hasTurns(){
#ifndef DEBUG
    return false;
#else
    return turns > NO_TURNS;
#endif
}

void Player::setTurns(int numberOfTurns) {
    turns = numberOfTurns;
}

void Player::addTurns(int numberOfturns) {
    turns += numberOfturns;
}

void Player::endTurn() {
    turns--;
}