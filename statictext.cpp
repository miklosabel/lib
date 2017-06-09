#include "statictext.hpp"

using namespace std;
using namespace genv;

Statictext::Statictext() {}
Statictext::Statictext(int x, int y, string _s) : Widget(x, y)
{
    s = _s;
    sizeX = gout.twidth(s);
    sizeY = gout.cascent() + gout.cdescent();
}
Statictext::Statictext(int x, int y, int sx, int sy, string _s)
    : Widget(x, y, sx, sy),
    s(_s)
{
    s = _s;
}

void Statictext::Draw() const
{
        gout    << move_to(itsX, itsY+gout.cascent())
                << color(250,250,250)
                << text(s);
}

void Statictext::Handle(event ev)
{
}

void Statictext::setText(string text)
{
    s = text;
    sizeX = gout.twidth(s);
}

string Statictext::getText() const { return s; }

