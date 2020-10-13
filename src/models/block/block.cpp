#include <string>

#include "assets/colors.h"

#include "models/block/block.h"

Block::Block(std::string blockName, Color blockColor) {
    name = blockName;
    color = blockColor;
}