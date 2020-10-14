#include <iostream>
#include <stdlib.h>

#include "die.h"

#include "assets/contants.h"

Die::Die() : minLimit(MIN_DIE_VALUE), maxLimit(MAX_DIE_VALUE) {}

int Die::throwDie() {
	return (rand() % maxLimit) + minLimit;
}