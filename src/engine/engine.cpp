#include <vector>

#include "engine.h"
#include "match/match.h"

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"
#include "models/board/board.h"
#include "models/die/die.h"

Engine::Engine(const Controller& controller, const ViewPort& viewPort) : viewPort(viewPort), controller(controller) {
	gameBoard = Board();
	gameDie = Die();
}

void Engine::beginMatch() {
	initiatePlayers();
	Match match = Match(players, gameBoard);
	match.startRounds(viewPort, controller);
	match.showResult(viewPort);
}

void Engine::initiatePlayers() {
	int numberOfPlayers = controller.getNumberOfPlayers();
	players = std::vector<Player>();
	while (numberOfPlayers--) players.push_back(createPlayer());
}

Player Engine::createPlayer() {
	// TODO : Make actual player
	return Player(PlayerPeices::DOG, gameDie);
}