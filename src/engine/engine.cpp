#include <vector>

#include "engine.h"
#include "match/match.h"

#include "io/viewPort.h"
#include "io/controller.h"

#include "assets/playerPieces.h"

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
	// TODO : Handle exception thrown by takePiece()
	PlayerPieceAllocator* playerPieces = PlayerPieceAllocator::getPlayerPieceAllocatorInstance();
	auto availPieces = playerPieces->getAvailablePieces();
	auto piece = playerPieces->takePiece(availPieces[0]);
	return Player(piece, gameDie);
}