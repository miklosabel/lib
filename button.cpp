#include <iostream>
#include "button.hpp"
#include <string>

using namespace std;
using namespace genv;

//funktor::funktor(int &_c, int &_d)
//{
//    c = _c;
//    d = _d;
//}

//void funktor::operator()()
//{
//    d=c;
//    cout<<"d:"<<d<<endl;
//}

Button::Button() : Widget() {}
Button::Button(int x, int y, string _s) : Widget(x, y)
{
    s = _s;
    sizeX = gout.twidth(s) + 2*gout.twidth(" ");
    sizeY = gout.cascent() + gout.cdescent();
    pressed = false;
}
Button::Button(int x, int y, int sx, int sy, string _s)
            : Widget(x, y, sx, sy),
            s(_s),
            pressed(false) {}


void Button::Draw() const
{
    if (this -> pressed)
    {
        gout    << move_to(itsX, itsY)  //doboz rajzolasa lehet opcios feladat (textbox)
                << color(112,150,111)
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
    if (Selected(ev.pos_x, ev.pos_y))
    {
        this -> HandleSelected(ev);
        if (ev.button == btn_left)
        {
            this -> pressed = true;
        }
        else
        {
            this -> pressed = false;
        }
        }
    if(pressed) callback();

//    if(ev.type == ev_mouse)
//    {
//        if(ev.button == btn_left && !pressed)
//        {
//            cout << "eger\n";
//            if( Selected(ev.pos_x, ev.pos_y) )
//            {
//                callback();
//                cout << "callback\n";
//                this->pressed = true;
//            }
//            else
//            {
//                pressed = false;
//            }
//        } else if (ev.button == -btn_left) pressed = false;
//    }


//    else if( (focused && ev.button == -btn_left ) || (!focused && ev. button == btn_left ))
//    {
//        pressed = false;  //felengedésre ne legyen megnyomva
//    }

}


bool Button::isPressed() const
{
    return pressed;
}

void Button::setX(int x)
{
    itsX = x;
}







