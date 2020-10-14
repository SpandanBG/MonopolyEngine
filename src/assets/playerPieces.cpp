#include "playerPieces.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

#include "contants.h"

PlayerPieceAllocator* PlayerPieceAllocator::instance = nullptr;

PlayerPieceAllocator* PlayerPieceAllocator::getPlayerPieceAllocatorInstance() {
	if (instance == nullptr) {
		instance = new PlayerPieceAllocator();
	}
	return instance;
}

PlayerPieceAllocator::PlayerPieceAllocator() : piecesAvailabilityMap(std::unordered_map<Piece::Type, bool>()) {
	for (Piece::Type peice : Piece::ALL) piecesAvailabilityMap[peice] = AVAILABLE;
}

std::vector<Piece::Type> PlayerPieceAllocator::getAllPieces() {
	return Piece::ALL;
}

std::vector<Piece::Type> PlayerPieceAllocator::getAvailablePieces() {
	auto availPieces = std::vector<Piece::Type>();
	auto isAvailable = [this](Piece::Type peice) { return piecesAvailabilityMap[peice]; };
	std::copy_if(Piece::ALL.begin(), Piece::ALL.end(), std::back_inserter(availPieces), isAvailable);
	return availPieces;
}

PlayerPiece PlayerPieceAllocator::takePiece(Piece::Type piece) {
	if (!piecesAvailabilityMap[piece]) throw "PLAYER PIECE TAKEN EXCEPTION";
	piecesAvailabilityMap[piece] = NOT_AVAILABLE;
	return PlayerPiece(piece);
}

PlayerPiece::PlayerPiece(Piece::Type piece) : piece(piece) {}

Piece::Type PlayerPiece::getPiece() {
	return piece;
}
