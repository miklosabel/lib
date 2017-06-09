#include "textbox.hpp"

using namespace std;
using namespace genv;

Textbox::Textbox() {};
Textbox::Textbox(int x, int y) : Widget(x, y)
{
    s = "\0";
    sizeX = gout.twidth(s);
    sizeY = 4 + gout.cascent() + gout.cdescent(); // a 10 meg a 4 a "keret"
    clicked = false;
}
Textbox::Textbox(int x, int y, string _s) : Widget(x, y)
{
    s = _s;
    sizeX = gout.twidth(s) + 10;
    sizeY = 4 + gout.cascent() + gout.cdescent(); // a 10 meg a 4 a "keret"
    clicked = false;
}
Textbox::Textbox(int x, int y, int sx, int sy, string _s) : Widget(x, y, sx, sy)
{
    s = _s;
    clicked = false;
}

void Textbox::Draw() const
{
    gout << color(90,109,89);
    gout << move_to(itsX, itsY)
         << box(sizeX,sizeY)
         << move_to(itsX+5, itsY+gout.cascent()+2)
         << color(250,250,250);
    if (s.empty()) gout << text("");
    if (!s.empty()) gout << text(s);
    if (clicked) gout << color(250,250,250) << text("|"); //kurzor

}

void Textbox::Handle(event ev)
{
    this -> HandleSelected(ev);
    if ( Selected(ev.pos_x, ev.pos_y) && ev.button == btn_left ) clicked = !clicked;
    if ( !Selected(ev.pos_x, ev.pos_y) && ev.button == btn_left ) clicked = false;

    ///gepelesi funkcio megirasa
    if (clicked && ev.type == ev_key)
    {
        if (ev.keycode  >= ' ' && ev.keycode < 255)
        {
            s += (char)ev.keycode;
            sizeX = gout.twidth(s)+10;
        }
        if (ev.keycode == key_backspace && !s.empty())
        {
            s.pop_back();
            sizeX = gout.twidth(s)+10;
        }
    }
    ///kulonbozo meretek beallitasa rajzolashoz (Draw-ban nem lehet, mert const)
    if (s.empty()) sizeX = gout.twidth("   ") + 10;
    if (s.empty() && clicked) sizeX = gout.twidth("|") + 10;
    if (!s.empty() && clicked) sizeX = gout.twidth(s) + 10;
}



