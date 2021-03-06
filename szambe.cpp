#include "szambe.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace genv;

Szambe::Szambe() {}
Szambe::Szambe(int x, int y, int _minLimit, int _maxLimit, int _num)
    : Widget(x, y)
{
    minLimit = _minLimit;
    maxLimit = _maxLimit;
    num = _num;
    st = new Statictext(x, y, to_string(num));

    decrement = new Button( x + gout.twidth(to_string(num))+ 2, y, "<" );
    decrement -> setCallBack([&]()
    {
        this -> DecrementNum();
    });

    increment = new Button( x + gout.twidth(to_string(num))+ 2 + gout.twidth(" < ") + 2, y, ">" );
    increment -> setCallBack([&]()
    {
        this -> IncrementNum();
    });

    ///alabb: ettol meg a sizeX nem valtozik ha set-eljuk
    ///a num mezot. ezt erdemes beleirni a setterbe!!!! (beleirtam)
    sizeX = gout.twidth(to_string(num))+ 2 + 2 * gout.twidth(" < ") + 2;
    sizeY = gout.cascent() + gout.cdescent();
    selected = false;
}

void Szambe::Draw() const
{
    gout << move_to(itsX, itsY)
         << color(112,150,111)
         << box(sizeX, sizeY);

    gout << move_to(itsX, itsY);
    st -> Draw();
    decrement -> Draw();
    increment -> Draw();
}

void Szambe::Handle(event ev)
{

    if (this->Selected(ev.pos_x, ev.pos_y))
    {
        ///gombok megnyomasat szabalyzo fv-ek hivasa
        increment -> Handle(ev);
        decrement -> Handle(ev);

        ///gorgetheto beallitas
        if (ev.button == btn_wheeldown) DecrementNum();
        if (ev.button == btn_wheelup) IncrementNum();

        ///atfordulast lehetove tevo utasitasok- trukkozni kellett, a hatarokat is egy-egyel ki kell tolni
        if (num >= maxLimit) num = minLimit+1;
        if (num <= minLimit) num = maxLimit-1;
    }

    ///keretrajzolas, ha folotte az eger
    this -> HandleSelected(ev);

    ///setelt szam kirajzolasahoz szukseges rajzolasi muveletek, ha szamjegyvaltas tortenik
    st -> setText( to_string(num) );
    decrement -> setX(itsX + gout.twidth(to_string(num))+ 2); //itsX a szambe x-e
    increment -> setX(itsX + gout.twidth(to_string(num))+ 2 + gout.twidth(" < ") + 2);
    sizeX = gout.twidth(to_string(num)) + 2 + 2*gout.twidth(" < ") + 2;

    //egyszer lehet hogy kellene bele irni egy kulon fv-t, melyet meghiv, ha tullepnek a hatart
}

void Szambe::IncrementNum()
{
    if (this->num < this->maxLimit) this->num++;
}

void Szambe::DecrementNum()
{
    if (this->num > this->minLimit) this->num--;
}

int Szambe::getNum() { return num; }
