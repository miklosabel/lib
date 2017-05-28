#include <iostream>
#include "button.hpp"
#include <string>

using namespace std;
using namespace genv;

Button::Button() : Widget() {}
Button::Button(int x, int y, string _s) : Widget(x, y)
{
    s = _s;
    sizeX = gout.twidth(s) + 2*gout.twidth(" ");
    sizeY = gout.cascent() + gout.cdescent();
    pressed = false;
}
Button::Button(int x, int y, int sx, int sy, string _s, /*function<void()>*/funktor k)
            : Widget(x, y, sx, sy)
{
    s = _s;
    pressed = false;
    kacsa = k;
}

void Button::Draw() const
{
    if (pressed)
    {
        gout    << move_to(itsX, itsY)  //doboz rajzolasa lehet opcios feladat (textbox)
                << color(112,150,111)
                << box(sizeX,sizeY)
                << move_to(itsX+gout.twidth(" "), itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    }
    else if(focused)
    {
        gout    << move_to(itsX, itsY)  //doboz rajzolasa lehet opcios feladat (textbox)
                << color(112,136,111)
                << box(sizeX,sizeY)
                << move_to(itsX+gout.twidth(" "), itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    }
    else
    {
        gout    << move_to(itsX, itsY)  //doboz rajzolasa lehet opcios feladat (textbox)
                << color(81,109,107)
                << box(sizeX,sizeY)
                << move_to(itsX+gout.twidth(" "), itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    }
}

void Button::Handle(event ev)
{
    setFocus(ev.pos_x, ev.pos_y);
    if( focused && ev.button == btn_left )
    {
        if(!pressed) Action();
        pressed = true;    //a bekattintott gomb legyen megnyomva (nem jobb megoldas a pressed = !pressed?)
    }
    else if( (focused && ev.button == -btn_left ) || (!focused && ev. button == btn_left ))
    {
        pressed = false;  //felengedésre ne legyen megnyomva
    }

}

void Button::Action()
{
    kacsa();
}

funktor::funktor(int &_c, int &_d)
{
    c = _c; d = _d;
}

void funktor::operator()()
{
    d=c;cout<<"d:"<<d<<endl;
}

bool Button::isPressed() const
{
    return pressed;
}

void Button::setX(int x)
{
    itsX = x;
}


