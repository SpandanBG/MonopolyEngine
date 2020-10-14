#ifndef ENGINE_H
#define ENGINE_H

#include <vector>

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"
#include "models/board/board.h"
#include "models/die/die.h"

class Engine {
private:
	const ViewPort& viewPort;
	const Controller& controller;

	std::vector<Player> players;
	Board gameBoard;
	Die gameDie;

	void initiatePlayers();
	Player createPlayer(PlayerPieceAllocator*);

public:
	Engine(const Controller&, const ViewPort&);
	void beginMatch();
};

#endif