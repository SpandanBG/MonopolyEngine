#ifndef MATCH_H
#define MATCH_H

#include <vector>

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"
#include "models/board/board.h"

class Match {
private:
	std::vector<Player>& playPool;
	Board& board;

	std::vector<Player> skipPool, deadPool;

	void resetPlayerTurns();
	bool matchOver();

public:
	Match(std::vector<Player>&, Board&);

	void startRounds(const ViewPort&, const Controller&);
	void showResult(const ViewPort&);
};

#endif