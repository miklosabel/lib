#include "graphics.hpp"
#include "widget.hpp"
#include <iostream>

using namespace genv;

const int contourWidth = 2;

Widget::Widget()
{
    itsX = 0;
    itsY = 0;
    sizeX=0;
    sizeY=0;
};
Widget::Widget(int x, int y) : itsX(x), itsY(y)
{
}
Widget::Widget(int x, int y, int sx, int sy) : itsX(x), itsY(y), sizeX(sx), sizeY(sy)
{
}

int Widget::getY() const
{
    return itsY;
}

void Widget::setY(int y)
{
    itsY = y;
}



void Widget::Draw() const {}

void Widget::DrawContour(bool clicked) const
{
    if(clicked)
    {
        gout << move_to(itsX-contourWidth, itsY-contourWidth)
             << color(240,240,240)
             << box( sizeX + 2*contourWidth, sizeY + 2*contourWidth );
    }
    else
    {
        gout << move_to(itsX-contourWidth, itsY-contourWidth)
             << color(171,230,170)
             << box( sizeX + 2*contourWidth, sizeY + 2*contourWidth );
    }
}

void Widget::Handle(event ev)
{
    this -> HandleSelected(ev);
}

void Widget::HandleSelected(event ev)
{
    this -> DrawContour(this->Selected(ev.pos_x,ev.pos_y));
}

bool Widget::Selected(int mouseX,int mouseY) const
{
    return (mouseX > itsX &&
            mouseX < itsX + sizeX &&
            mouseY > itsY &&
            mouseY < itsY + sizeY );
}

void Widget::getter(int i) const
{
    std::cout << i <<"\t" << itsX << "\t" << itsY << "\t" << sizeX << "\t" << sizeY << "\n";
}
