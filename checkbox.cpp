#include "checkbox.hpp"

using namespace genv;

Checkbox::Checkbox(int x, int y, int sx, int sy) : Widget(x,y,sx,sy), checked(false)
{
    sizeY = sx; ///legyen inkabb negyzet alaku akkormar
}

void Checkbox::Draw() const
{
    gout<< move_to(itsX, itsY)
        << box(sizeX, sizeY);
    gout<< move_to(itsX+2, itsY+2)
        << color(81,109,107)
        << box(sizeX-4, sizeY-4);

    if (checked)
    {

        gout << color(240,240,240);
        gout << move_to(itsX+4, itsY+4)
             << line(sizeX-8, sizeY-8);
        gout << move_to(itsX+5, itsY+4)
             << line(sizeX-8, sizeY-8);
        gout << move_to(itsX+sizeX-4, itsY+4)
             << line(-sizeX+8, sizeY-8);
        gout << move_to(itsX+sizeX-5, itsY+4)
             << line(-sizeX+8, sizeY-8);
    }
}

void Checkbox::Handle(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left && Selected(ev.pos_x, ev.pos_y))
        checked = !checked;
}

bool Checkbox::isChecked() const
{
    return checked;
}
