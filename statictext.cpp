#include "statictext.hpp"

using namespace std;
using namespace genv;

Statictext::Statictext() {}
Statictext::Statictext(int x, int y, string _s) : Widget(x, y)
{
    s = _s; 
    sizeX = gout.twidth(s);
    sizeY = gout.cascent() + gout.cdescent();
    selected = false;
}
Statictext::Statictext(int x, int y, int sx, int sy, string _s) : Widget(x, y, sx, sy)
{
    s = _s; 
    selected = false;
}

void Statictext::Draw() const
{
    if(selected)
    {
        gout    << move_to(itsX, itsY)
                << color(112,150,111)
                << box(sizeX,sizeY)
                << move_to(itsX, itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    } 
    else if (focused)
    {
        gout    << move_to(itsX, itsY)
                << color(112,136,111)
                << box(sizeX,sizeY)
                << move_to(itsX, itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    }
    else 
    {
        gout    << move_to(itsX, itsY)
                << color(81,109,107)
                << box(sizeX,sizeY)
                << move_to(itsX, itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
    }  
}

void Statictext::Handle(event ev)  
{
    setFocus(ev.pos_x, ev.pos_y); //eger folotte van-e
    //adott peldany ki van-e valasztva egerrel
    if( focused && ev.button == btn_left ) selected = !selected;
    if( !focused && ev.button == btn_left ) selected = false;
}

void Statictext::setText(string text)
{
    s = text;
    sizeX = gout.twidth(s);
}

string Statictext::getText() const { return s; }

bool Statictext::isSelected() const{ return selected; }
void Statictext::setSelected(bool b) { selected = b; }

int Statictext::getSizeX() const { return sizeX; }
void Statictext::setSizeX(int sx) { sizeX = sx; }