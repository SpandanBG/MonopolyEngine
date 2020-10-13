#include <iostream>
#include <string>

#include "viewPort.h"

void ViewPort::notifyPlayer(std::string message) const {
	std::cout << message;
}