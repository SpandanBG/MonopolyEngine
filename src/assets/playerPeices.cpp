#include "playerPeices.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

PlayerPeice* PlayerPeice::instance = nullptr;

PlayerPeice* PlayerPeice::getPlayerPeiceInstance() {
	if (instance == nullptr) {
		instance = new PlayerPeice();
	}
	return instance;
}

PlayerPeice::PlayerPeice() : peices(std::unordered_map<PeiceTypes, bool>()) {
	peices[PeiceTypes::DOG] = true;
	peices[PeiceTypes::SHIP] = true;
	peices[PeiceTypes::HAT] = true;
	peices[PeiceTypes::BIN] = true;
	peices[PeiceTypes::CAR] = true;
	peices[PeiceTypes::SHOW] = true;
	peices[PeiceTypes::POT] = true;
}

std::vector<PeiceTypes> PlayerPeice::getAllPeices() {
	return std::vector<PeiceTypes> {
		PeiceTypes::DOG,
		PeiceTypes::SHIP,
		PeiceTypes::HAT,
		PeiceTypes::BIN,
		PeiceTypes::CAR,
		PeiceTypes::SHOW,
		PeiceTypes::POT,
	};
}

std::vector<PeiceTypes> PlayerPeice::getAvailablePeices() {
	auto allPeices = getAllPeices();
	auto availPeices = std::vector<PeiceTypes>();
	auto isAvailable = [this](PeiceTypes peice) { return peices[peice]; };
	std::copy_if(allPeices.begin(), allPeices.end(), std::back_inserter(availPeices), isAvailable);
	return availPeices;
}

void PlayerPeice::takePeice(PeiceTypes peice) {
	if (!peices[peice]) throw "PLAYER PEICE TAKEN EXCEPTION";
	peices[peice] = false;
}
