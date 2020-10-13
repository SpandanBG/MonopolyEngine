#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "viewPort.h"

class Controller {
private:
	const ViewPort &viewPort;

public:
	Controller(const ViewPort &);
	int getNumberOfPlayers() const;
};

#endif