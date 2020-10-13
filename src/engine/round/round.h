#ifndef ROUND_H
#define ROUND_H

#include <vector>

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"

class Round {
private:
	std::vector<Player>& playPool, & skipPool, & deadPool;

	void playTurn(Player&, const ViewPort&, const Controller&);

public:
	Round(std::vector<Player>&, std::vector<Player>&, std::vector<Player>&);

	void startTurns(const ViewPort&, const Controller&);
};

#endif