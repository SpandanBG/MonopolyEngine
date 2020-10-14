#include "playerPieces.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <optional>

#include "contants.h"

PlayerPieceAllocator* PlayerPieceAllocator::instance = nullptr;

PlayerPieceAllocator* PlayerPieceAllocator::getPlayerPieceAllocatorInstance() {
	if (instance == nullptr) {
		instance = new PlayerPieceAllocator();
	}
	return instance;
}

void PlayerPieceAllocator::deletePlayerPieceAllocatorInstance() {
	delete instance;
}

PlayerPieceAllocator::PlayerPieceAllocator() : piecesAvailabilityMap(std::unordered_map<Piece::Type, bool>()) {
	for (Piece::Type peice : Piece::ALL) piecesAvailabilityMap[peice] = AVAILABLE;
}

const std::vector<Piece::Type>& PlayerPieceAllocator::getAllPieces() {
	return Piece::ALL;
}

const std::unordered_map<Piece::Type, bool>& PlayerPieceAllocator::getPiecesAvailability() {
	return piecesAvailabilityMap;
}

std::optional<PlayerPiece> PlayerPieceAllocator::takePiece(Piece::Type piece) {
	if (!piecesAvailabilityMap[piece]) return {};
	piecesAvailabilityMap[piece] = NOT_AVAILABLE;
	return std::optional<PlayerPiece> { PlayerPiece(piece) };
}

PlayerPiece::PlayerPiece(Piece::Type piece) : piece(piece) {}

Piece::Type PlayerPiece::getPiece() {
	return piece;
}
