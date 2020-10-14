#include <string>
#include <vector>

#include "board.h"

#include "assets/colors.h"

#include "models/die/die.h"
#include "models/block/block.h"

Board::Board() : blocks(std::vector<Block>()) {
	blocks.push_back(Block("GO", Color::NO_COLOR));
	blocks.push_back(Block("Guwahati", Color::RED));
	blocks.push_back(Block("Bhubaneshwar", Color::GREEN));
}

int Board::getNewPosition(int playerPosition, int dieOne, int dieTwo) {
	int steps = playerPosition + dieOne + dieTwo;
	return steps % blocks.size();
}

Block* Board::getBlockByPosition(int position) {
	return &blocks[position];
}