#include <vector>

#include "round.h"

#include "io/viewPort.h"
#include "io/controller.h"

#include "engine/turn/turn.h"

#include "models/player/player.h"

Round::Round(
	std::vector<Player>& playPool,
	std::vector<Player>& skipPool,
	std::vector<Player>& deadPool
) : playPool(playPool), skipPool(skipPool), deadPool(deadPool) {}

void Round::startTurns(const ViewPort& viewPort, const Controller& controller) {
	for (Player& player : playPool) {
		playTurn(player, viewPort, controller);
	}
}

void Round::playTurn(Player& player, const ViewPort& viewPort, const Controller& controller) {
	Turn turn = Turn(player);
	turn.play(viewPort, controller);
	if (player.hasTurns()) playTurn(player, viewPort, controller);
}
