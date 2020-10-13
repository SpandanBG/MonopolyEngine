#include <utility>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Monopoly TXT.h"

#include "assets/playerPeices.h"
#include "assets/colors.h"

#include "models/die/die.h"
#include "models/player/player.h"
#include "models/block/block.h"
#include "models/board/board.h"

#include "io/viewPort.h"
#include "io/controller.h"

#include "engine/engine.h"

int main() {
	srand(time(NULL));

	const ViewPort viewPort{};
	const Controller controller{ viewPort };

	Engine gameEngine = Engine{ controller , viewPort };

	gameEngine.beginMatch();

	return 0;
}
