#define DEBUG

#include <algorithm>
#include <vector>

#include "match.h"

#include "engine/round/round.h"

#include "io/viewPort.h"
#include "io/controller.h"

#include "assets/contants.h"

Match::Match(std::vector<Player>& players, Board& board) : playPool(players), board(board) {
	skipPool = std::vector<Player>();
	deadPool = std::vector<Player>();
}

void Match::startRounds(const ViewPort& viewPort, const Controller& controller) {
	resetPlayerTurns();
	Round round = Round(playPool, skipPool, deadPool);
	round.startTurns(viewPort, controller);
	if (!matchOver()) startRounds(viewPort, controller);
}

void Match::showResult(const ViewPort& viewPort) {}

void Match::resetPlayerTurns() {
	for (Player& player : playPool) {
		player.setTurns(DEFAULT_TURNS);
	}
}

bool Match::matchOver() {
#ifdef DEBUG
	return true;
#else
	auto onePlayerLeft = playPool.size() == ONE_PLAYER;
	auto noSkippers = skipPool.size() == NO_PLAYERS;
	return onePlayerLeft && noSkippers;
#endif
}