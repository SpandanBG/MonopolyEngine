#include <iostream>

#include "controller.h"

Controller::Controller(const ViewPort& viewPort) : viewPort(viewPort) {}

int Controller::getNumberOfPlayers() const {
	int numberOfPlayers;
	viewPort.notifyPlayer("Enter the number of players : ");
	std::cin >> numberOfPlayers;
	return numberOfPlayers;
}