#ifndef AMOBAJATEK_H
#define AMOBAJATEK_H

#include "jatekmester.h"
#include "graphics.hpp"

class AmobaJatek {
private:
    jatekmester game_master;
public:
    AmobaJatek(int x, int y, int size_x, int size_y);
    void futtat();
};

#endif // AMOBAJATEK_H
