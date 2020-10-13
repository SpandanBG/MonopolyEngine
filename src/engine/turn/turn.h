#ifndef TURN_H
#define TURN_H

#include <vector>

#include "io/viewPort.h"
#include "io/controller.h"

#include "models/player/player.h"

class Turn {
private:
	Player& player;

public:
	Turn(Player&);
	void play(const ViewPort&, const Controller&);
};

#endif
