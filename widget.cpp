#include "graphics.hpp"
#include "widget.hpp"
#include <iostream>

Widget::Widget() 
{
    itsX = 0;
    itsY = 0;
    sizeX=0;
    sizeY=0;
    focused = false;
};
Widget::Widget(int x, int y) : itsX(x), itsY(y)
{
    focused = false;
}
Widget::Widget(int x, int y, int sx, int sy) : itsX(x), itsY(y), sizeX(sx), sizeY(sy)
{
    focused = false;
}

int Widget::getY() const
{
    return itsY;
}

void Widget::setY(int y)
{
    itsY = y;
}

void Widget::setFocus(int mouseX, int mouseY)
{
    //allandoan ellenorizni kell hogy folotte van-e az eger,
    //ezert a leszarmazottak ezt a handle fv-ukben szepen meghivjak majd
     if     (mouseX > itsX &&
            mouseX < itsX + sizeX &&
            mouseY > itsY &&
            mouseY < itsY + sizeY )
    {
        focused = true;
    }
    else focused = false;
}

bool Widget::isFocused() const    //getter
{
   return focused;
}

void Widget::Draw() const {}

void Widget::Handle(genv::event ev) {}

bool Widget::is_selected(int mouseX,int mouseY) const
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
