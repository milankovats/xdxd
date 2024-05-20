
#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class Widget {
protected:
    int x, y, size_x, size_y;

public:
    Widget(int x, int y, int size_x, int size_y);
    virtual void draw();
    virtual void handle(genv::event ev) = 0;
    //virtual bool is_selected(int mx, int my) const;
};

#endif // WIDGET_H
