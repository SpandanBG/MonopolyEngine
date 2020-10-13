#include "turn.h"

#include <vector>

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"

Turn::Turn(Player& player) : player(player) {}

void Turn::play(const ViewPort& viewPort, const Controller& controller) {
	player.endTurn();
}