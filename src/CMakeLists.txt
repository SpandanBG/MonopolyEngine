# CMakeList.txt : CMake project for Monopoly TXT, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMakeTarget "Monopoly TXT.cpp" "Monopoly TXT.h" "models/die/die.h" "models/die/die.cpp" "models/player/player.h" "models/player/player.cpp" "assets/colors.h" "assets/playerPeices.h" "assets/contants.h" "models/block/block.h" "models/block/block.cpp" "models/board/board.h" "models/board/board.cpp" "io/viewPort.h" "io/controller.h" "engine/engine.h" "engine/engine.cpp" "engine/match/match.h" "engine/match/match.cpp" "io/controller.cpp" "io/viewPort.cpp" "engine/round/round.h" "engine/round/round.cpp" "engine/turn/turn.h" "engine/turn/turn.cpp"  "assets/playerPeices.cpp"    )


# TODO: Add tests and install targets if needed.
