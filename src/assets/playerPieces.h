#ifndef PLAYER_PEICE_H
#define PLAYER_PEICE_H

#include <utility>
#include <vector>
#include <unordered_map>

namespace Piece {
	enum class Type { DOG, SHIP, HAT, BIN, CAR, SHOW, POT };
	static const std::vector<Type> ALL = {
		Type::DOG, Type::SHIP, Type::HAT, Type::BIN, Type::CAR, Type::SHOW, Type::POT
	};
}

class PlayerPiece {
private:
	Piece::Type piece;
	PlayerPiece(Piece::Type);
public:
	Piece::Type getPiece();
	friend class PlayerPieceAllocator;
};

class PlayerPieceAllocator {
private:
	static PlayerPieceAllocator* instance;

	std::unordered_map<Piece::Type, bool> piecesAvailabilityMap;

	PlayerPieceAllocator();

public:
	static PlayerPieceAllocator* getPlayerPieceAllocatorInstance();

	std::vector<Piece::Type> getAvailablePieces();
	std::vector<Piece::Type> getAllPieces();
	PlayerPiece takePiece(Piece::Type);
};

#endif