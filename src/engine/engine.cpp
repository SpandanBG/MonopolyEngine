#include <vector>
#include <optional>

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
	PlayerPieceAllocator* pieceAllocator = PlayerPieceAllocator::getPlayerPieceAllocatorInstance();
	while (numberOfPlayers--) players.push_back(createPlayer(pieceAllocator));
	PlayerPieceAllocator::deletePlayerPieceAllocatorInstance();
}

Player Engine::createPlayer(PlayerPieceAllocator* pieceAllocator) {
	Piece::Type selectedPiece = controller.selectPlayerPiece(
		pieceAllocator->getAllPieces(), pieceAllocator->getPiecesAvailability()
	);
	std::optional<PlayerPiece> maybePiece = pieceAllocator->takePiece(selectedPiece);
	if (maybePiece.has_value()) return Player(maybePiece.value(), gameDie);
	else viewPort.displaySelectionError();
	return createPlayer(pieceAllocator);
}