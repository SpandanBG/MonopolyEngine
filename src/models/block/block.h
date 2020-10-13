#ifndef BLOCK_H
#define BLOCK_H

#include <string>

#include "assets/colors.h"

class Block {
private:
    std::string name;
    Color color;

public:
    Block(std::string name, Color color);
};

#endif