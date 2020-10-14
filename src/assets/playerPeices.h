#ifndef ANIMAL_H
#define ANIMAL_H

#include <utility>
#include <unordered_map>

enum class PeiceTypes {
	DOG, SHIP, HAT, BIN, CAR, SHOW, POT
};

class PlayerPeice {
private:
	static PlayerPeice* instance;

	std::unordered_map<PeiceTypes, bool> peices;

	PlayerPeice();

public:
	static PlayerPeice* getPlayerPeiceInstance();

	std::vector<PeiceTypes> getAvailablePeices();
	std::vector<PeiceTypes> getAllPeices();
	void takePeice(PeiceTypes);
};

#endif