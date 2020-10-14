#ifndef PLAYER_PEICE_H
#define PLAYER_PEICE_H

#include <utility>
#include <vector>
#include <unordered_map>
#include <optional>
#include <string>

namespace Piece {
	enum class Type { DOG, SHIP, HAT, BIN, CAR, SHOW, POT };
	static const std::vector<Type> ALL = {
		Type::DOG, Type::SHIP, Type::HAT, Type::BIN, Type::CAR, Type::SHOW, Type::POT
	};
	static std::string ToString(Piece::Type piece) {
		std::string typeName;
		switch (piece) {
		case Type::DOG: typeName = "DOG"; break;
		case Type::SHIP: typeName = "SHIP"; break;
		case Type::HAT: typeName = "HAT"; break;
		case Type::BIN: typeName = "BIN"; break;
		case Type::CAR: typeName = "CAR"; break;
		case Type::SHOW: typeName = "SHOW"; break;
		case Type::POT: typeName = "POT"; break;

		};
		return typeName;
	}
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
	static void deletePlayerPieceAllocatorInstance();

	const std::vector<Piece::Type>& getAllPieces();
	const std::unordered_map<Piece::Type, bool>& getPiecesAvailability();
	std::optional<PlayerPiece> takePiece(Piece::Type);
};

#endif