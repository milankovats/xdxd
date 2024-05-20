
#ifndef JATEKMESTER_H
#define JATEKMESTER_H

#include "widget.h"
#include "tabla.h"

class jatekmester : public Widget
{
private:
    Tabla* jatekter[20][20];
    int nyertes;
    bool gameover;

public:
    jatekmester(int x, int y, int size_x, int size_y);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    bool check_winner(unsigned int player);
    bool check_tabla();
    void set_winner();
    void game_overset();
};

#endif // JATEKMESTER_H
