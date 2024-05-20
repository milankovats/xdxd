#include "amobajatek.h"

AmobaJatek::AmobaJatek(int x, int y, int size_x, int size_y)
    : game_master(x, y, size_x, size_y) {}

void AmobaJatek::futtat() {
    const int window_width = 600;
    const int window_height = 600;

    genv::gout.open(window_width, window_height);
    genv::event ev;

    while (genv::gin >> ev && ev.keycode != genv::key_escape) {
        if (ev.type == genv::ev_mouse || ev.type == genv::ev_key) {
            game_master.handle(ev);
            genv::gout << genv::color(0, 0, 0) << genv::move_to(0, 0) << genv::box(window_width, window_height);
            game_master.draw();
            genv::gout << genv::refresh;
        }
    }
}
