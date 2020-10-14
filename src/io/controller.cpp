#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>

#include "controller.h"

Controller::Controller(const ViewPort& viewPort) : viewPort(viewPort) {}

int Controller::getNumberOfPlayers() const {
	int numberOfPlayers;
	viewPort.notifyPlayer("Enter the number of players : ");
	std::cin >> numberOfPlayers;
	viewPort.notifyPlayer("---\n");
	return numberOfPlayers;
}

Piece::Type Controller::selectPlayerPiece(
	std::vector<Piece::Type> allPieces,
	std::unordered_map<Piece::Type, bool> pieceAvailability
) const {
	auto availablePieces = std::vector<Piece::Type>();
	auto notAvailPieces = std::vector<Piece::Type>();

	auto isAvailable = [&pieceAvailability](Piece::Type piece) { return pieceAvailability[piece]; };
	auto notAvailable = [&isAvailable](Piece::Type piece) { return !isAvailable(piece); };

	std::copy_if(allPieces.begin(), allPieces.end(), std::back_inserter(availablePieces), isAvailable);
	std::copy_if(allPieces.begin(), allPieces.end(), std::back_inserter(notAvailPieces), notAvailable);

	if (notAvailPieces.size()) {
		viewPort.notifyPlayer("Taken Pieces: \n");
		for (Piece::Type& piece : notAvailPieces) viewPort.notifyPlayer(Piece::ToString(piece) + "\n");
		viewPort.notifyPlayer("---\n");
	}

	viewPort.notifyPlayer("Available Pieces: \n");
	for (int i = 0; i < availablePieces.size(); i++)
		viewPort.notifyPlayer(std::to_string(i) + " > " + Piece::ToString(availablePieces[i]) + "\n");
	viewPort.notifyPlayer("---\n");

	int selectedIndex;
	viewPort.notifyPlayer("Enter index of selected piece : ");
	std::cin >> selectedIndex;
	viewPort.notifyPlayer("---\n");

	selectedIndex %= availablePieces.size();

	return availablePieces[selectedIndex];
}