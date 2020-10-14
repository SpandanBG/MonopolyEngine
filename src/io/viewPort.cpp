#include <iostream>
#include <string>

#include "viewPort.h"

void ViewPort::notifyPlayer(std::string message) const {
	std::cout << message;
}

void ViewPort::displaySelectionError() const {
	std::cout << "INVALID SELECTION. PLEASE TRY AGAIN\n";
}