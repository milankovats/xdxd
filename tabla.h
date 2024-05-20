#ifndef TABLA_H
#define TABLA_H

#include "widget.h"

class Tabla : public Widget {
private:
    int x, y, size_x, size_y;
    int player;
public:
    Tabla(int x, int y, int size_x, int size_y);
    void draw();
    void handle(genv::event ev);
    virtual unsigned int getplayer() {return player;}
};

#endif // TABLA_H
