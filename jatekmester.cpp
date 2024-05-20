#include "jatekmester.h"
#include "graphics.hpp"
#include "tabla.h"
#include "iostream"

using namespace genv;
using namespace std;

unsigned int kor;

jatekmester::jatekmester(int x, int y, int size_x, int size_y)
    : Widget(x, y, size_x, size_y), nyertes(0), gameover(false) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            jatekter[i][j] = new Tabla(x + j * size_x, y + i * size_y, size_x, size_y);
        }
    }
}

void jatekmester::draw() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            jatekter[i][j]->draw();
        }
    }
}

void jatekmester::handle(event ev) {
    if (!gameover) {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                jatekter[i][j]->handle(ev);
            }
        }
        set_winner();
        if (check_tabla()) {
            game_overset();
        }
    }
}

bool jatekmester::check_winner(unsigned int player) {
    // Vízszintes ellenõrzés
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (jatekter[i][j]->getplayer() == player && jatekter[i][j + 1]->getplayer() == player &&
                jatekter[i][j + 2]->getplayer() == player && jatekter[i][j + 3]->getplayer() == player &&
                jatekter[i][j + 4]->getplayer() == player) {
                return true;
            }
        }
    }

    // Függõleges ellenõrzés
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (jatekter[i][j]->getplayer() == player && jatekter[i + 1][j]->getplayer() == player &&
                jatekter[i + 2][j]->getplayer() == player && jatekter[i + 3][j]->getplayer() == player &&
                jatekter[i + 4][j]->getplayer() == player) {
                return true;
            }
        }
    }

    // Átlós ellenõrzés (jobbra lefelé)
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (jatekter[i][j]->getplayer() == player && jatekter[i + 1][j + 1]->getplayer() == player &&
                jatekter[i + 2][j + 2]->getplayer() == player && jatekter[i + 3][j + 3]->getplayer() == player &&
                jatekter[i + 4][j + 4]->getplayer() == player) {
                return true;
            }
        }
    }

    // Átlós ellenõrzés (balra lefelé)
    for (int i = 0; i < 16; ++i) {
        for (int j = 4; j < 20; ++j) {
            if (jatekter[i][j]->getplayer() == player && jatekter[i + 1][j - 1]->getplayer() == player &&
                jatekter[i + 2][j - 2]->getplayer() == player && jatekter[i + 3][j - 3]->getplayer() == player &&
                jatekter[i + 4][j - 4]->getplayer() == player) {
                return true;
            }
        }
    }

    return false;
}

void jatekmester::set_winner() {
    if (check_winner(1)) {
        gameover = true;
        nyertes = 1;
    } else if (check_winner(2)) {
        gameover = true;
        nyertes = 2;
    }
}

bool jatekmester::check_tabla() {
    int szamlalo = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (jatekter[i][j]->getplayer() != 0) {
                szamlalo++;
            }
        }
    }
    return szamlalo == 400;
}

void jatekmester::game_overset() {
    gameover = true;
}
