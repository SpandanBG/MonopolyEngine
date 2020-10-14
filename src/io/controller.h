#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <unordered_map>

#include "viewPort.h"
#include "assets/playerPieces.h"

class Controller {
private:
	const ViewPort& viewPort;

public:
	Controller(const ViewPort&);
	int getNumberOfPlayers() const;
	Piece::Type selectPlayerPiece(
		std::vector<Piece::Type>, std::unordered_map<Piece::Type, bool>
	) const;
};

#endif