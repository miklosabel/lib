#include "szambe.hpp"
#include <vector>
#include <string>   
#include <iostream>

using namespace std;
using namespace genv;

Szambe::Szambe() {}
Szambe::Szambe(int x, int y, int _min, int _max, int _num)
            : Widget(x, y)
{
    min = _min;
    max = _max;
    num = _num;
    st = new Statictext(x, y, to_string(num));
    buttonvector.push_back( new Button(x + gout.twidth(to_string(num))+ 2, y, "<") );
    buttonvector.push_back( new Button(x + gout.twidth(to_string(num))+ 2 + gout.twidth(" < ") + 2, y, ">") );

    //alabb: ettol meg a sizeX nem valtozik ha set-eljuk 
    //a num mezot. ezt erdemes beleirni a setterbe!!!! (beleirtam)
    sizeX = gout.twidth(to_string(num))+ 2 + 2 * gout.twidth(" < ") + 2;
    sizeY = gout.cascent() + gout.cdescent();
    selected = false;
}

void Szambe::Draw() const
{
    gout << move_to(itsX, itsY);
    st -> setSelected(false);
    st -> Draw();
    buttonvector[0] -> Draw();
    buttonvector[1] -> Draw();
}

 void Szambe::Handle(event ev) 
{
    setFocus(ev.pos_x, ev.pos_y);   //ebbol tudja hogy folotte van-e az eger
    //belekattintva lehet a nyilakat hasznalni beallitasra
    if ( ev.type == ev_mouse && focused && ev.button == btn_left) selected = !selected; 
    else if (ev.button == btn_left && !focused) selected = false; 
    
    if (selected)
    {
        //tagvaltozok modositasat figyelo fv-ek
        st -> Handle(ev);
        for (int i = 0; i < buttonvector.size(); i++) buttonvector[i] -> Handle(ev);

        //gombnyomasra, egerkattintasra torteno valtoztatasok
        if ( (num > min &&  buttonvector[0] -> isPressed()) || (num > min && ev.keycode == key_down) ) num--;
        if ( (num < max && buttonvector[1] -> isPressed()) || (num < max && ev.keycode == key_up) ) num++;  
        if ( ((num-10) > min) && ev.keycode == key_pgdn) num-=10;
        if ( ((num+10) < max) && ev.keycode == key_pgup) num+=10;
    }

    //setelt szam kirajzolasahoz szukseges rajzolasi muveletek, ha szamjegyvaltas tortenik
    st -> setText( to_string(num) ); 
    buttonvector[0] -> setX(itsX + gout.twidth(to_string(num))+ 2); //itsX a szambe x-e
    buttonvector[1] -> setX(itsX + gout.twidth(to_string(num))+ 2 + gout.twidth(" < ") + 2);

    //egyszer lehet hogy kellene bele irni egy kulon fv-t, melyet meghiv, ha tullepnek a hatart
}

