#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "models/block/block.h"

class Board {
private:
    std::vector<Block> blocks;

public:
    Board();
    int getNewPosition(int, int, int);
    Block* getBlockByPosition(int);
};

#endif