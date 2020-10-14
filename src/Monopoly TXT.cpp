#include <stdlib.h>
#include <time.h>

#include "Monopoly TXT.h"

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
