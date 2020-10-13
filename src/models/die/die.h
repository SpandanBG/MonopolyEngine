#ifndef DIE_H
#define DIE_H

class Die {
private:
    int minLimit, maxLimit;

public:
    Die();
    int throwDie();
};

#endif