#ifndef PLAYER_H
#define PLAYER_H

#include <utility>

#include "assets/playerPieces.h"

#include "models/die/die.h"

class Player {
private:
	PlayerPiece peiceType;
	Die& die;

	int money, currentBoardPosition, turns;

public:
	Player(PlayerPiece, Die&);

	std::pair<int, int> throwDice();

	void creditMoney(int);
	void debitMoney(int);

	int getPosition();
	void setPosition(int);

	bool hasTurns();
	void setTurns(int);
	void addTurns(int);
	void endTurn();
};

#endif