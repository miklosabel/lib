#include "kival.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;


Kival::Kival(int x, int y, int eszam, int ran) : Widget(x, y)
{
    selected = false;
    pressed = -1;
    gorget = 0;
    elemszam = eszam;
    random = ran;
    sizeY = eszam * ((gout.cascent()+gout.cdescent())/2);
    sizeX = 150;

    int temp = gout.cascent()+gout.cdescent();
    //feltoltes elemekkel
    for(int i = 0; i < elemszam; i++)
    {
        stvector.push_back(new Statictext(itsX, itsY+i*temp, sizeX, temp, to_string(i*elemszam/random)));
    }
}

//gorgetest szabalyzo fv
void Kival::Scroll(int direction)
{
    int temp = gout.cascent()+gout.cdescent();
    for(int i = 0; i < stvector.size(); i++)
    {
        stvector[i]->setY( stvector[i]->getY()-temp );
    }
    if(direction == -1)
    {
        pressed++;
    }
    if(direction == 1)
    {
        pressed--;
    }

}

void Kival::Draw() const
{
    int temp = gout.cascent()+gout.cdescent();
    gout    << move_to(itsX, itsY)
            << color(81,109,107)
            << box(sizeX, sizeY);

    if(pressed != -1 && (itsY+pressed*20 > itsY) && (itsY+pressed*20 < itsY+sizeY))
    {
        gout << move_to(itsX,(itsY+pressed*20)) << color(0,0,255) << box(sizeX,temp);
    }


    for(int i=0; (i < 10) && i < stvector.size(); i++)
    {
        stvector[i+gorget]->Draw();
    }
}

void Kival::Handle(event ev)
{

    setFocus(ev.pos_x, ev.pos_y);
    if ( focused && ev.button == btn_left ) selected = !selected;
    if ( !focused && ev.button==btn_left ) selected = false;

    if( ev.button == btn_wheelup && gorget > 0 )
    {
        gorget--;
        Scroll(-1);
    }
    if(( ev.button == btn_wheeldown ) && (gorget+10 < stvector.size()))
    {
        gorget++;
        Scroll(1);
    }
    if (selected)
    {
        for (int i = 0; i < 10; i++)
        {
            if (selected==true && stvector[i]->isSelected())
            {
                if (ev.button == -1)
                {
                    pressed=i;
                }
            }
            else if (ev.button == btn_left)
            {
                pressed=-1;
            }
        }
    }
}

