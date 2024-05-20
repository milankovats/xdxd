#include "Tabla.h"
#include "graphics.hpp"

using namespace genv;

Tabla::Tabla(int x, int y, int size_x, int size_y)
    : Widget(x, y, size_x, size_y), x(x), y(y), size_x(size_x), size_y(size_y) {
    player =0;
    }

void Tabla::draw()
{
    switch (player) {
    case 0:
        gout << move_to(x, y) << color(255,255,255) << box(size_x, size_y);
        gout << move_to(x+1, y+1) << color(0,0,0) << box(size_x-2, size_y-2);
        break;
    case 1:
        gout << move_to(x, y) << color(255,255,255) << box(size_x, size_y);
        gout << move_to(x+1, y+1) << color(255,0,0) << box(size_x-2, size_y-2);
        break;
    case 2:
        gout << move_to(x, y) << color(255,255,255) << box(size_x, size_y);
        gout << move_to(x+1, y+1) << color(0,0,255) << box(size_x-2, size_y-2);
        break;
    }

}

void Tabla::handle(event ev)
{
    extern unsigned int kor;
    if (ev.type == ev_mouse && ev.pos_x > x && ev.pos_x < x+size_x && ev.pos_y > y && ev.pos_y < y+size_y && ev.button == btn_left && player == 0) {
        player = kor % 2==0 ? 1 : 2;
        kor++;
    }
}
