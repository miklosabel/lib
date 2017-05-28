///======================================================================================
///szambeallito mukodik csak.
///kivalaszto Draw() fv-be nem fut be sehogy sem, 6 ora alatt nem jottem ra miert.
///azert nem egyebkent, mert nem volt egy elem inicializalva a konstuktorban
///illetve veletlenul feluldeifnialtam a widget Draw()jat ettpl nem futott be abba (nyilvan)
///======================================================================================


#include <iostream>
#include "graphics.hpp"
#include "statictext.hpp"
#include "button.hpp"
#include "szambe.hpp"
#include "kival.hpp"

#include <vector>
#include <string>

using namespace std;
using namespace genv;

const int XX = 600;
const int YY = 600;

void Eventhandler(vector<Widget *> w);
void Clear();


int main()
{
    // int a = 5;
    // int b = 10;

    //funktor f(a, b); //funktor letrehozas (ugyanazt csinalja mint a lambda)

    //mindent ahol function van ki kell cserelni template parameterre hogy mukodjon lambdaval es funktorral is

    //Button * b1 = new Button(20,50, 30,20,"gg", f);

    //[&a,&b](){b=a;cout<<"b:"<<b<<endl;} lambda fv

    gout.open(XX,YY);
    Clear();

    vector<Widget *> w;

    Szambe * s1 = new Szambe(10, 10, 95, 152, 111);
    Szambe * s2 = new Szambe(200, 10, 30, 70, 55);

    Kival * k1 = new Kival(10, 100, 15, 3);
    Kival * k2 = new Kival(300,100, 20, 5);

    // w.push_back(b1);
    w.push_back(s1);
    w.push_back(s2);
    w.push_back(k1);
    w.push_back(k2);

    for (unsigned int i = 0; i < w.size(); i++)  w[i] -> Draw();
    gout << refresh;

    Eventhandler(w);

    return 0;
}



void Eventhandler(vector<Widget *> w)
{
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        Clear();

        for (unsigned int i = 0; i < w.size(); i++)
        {
            w[i] -> setFocus(ev.pos_x,ev.pos_y);
            w[i] -> Handle(ev);
            w[i] -> Draw();
        }
        ///azert elobb handle, mert így azt rajzolja ami tortenik
        ///nem pedig lerajzol valamit aztan valtoztat


        gout << refresh;
    }
}

void Clear()
{
    gout    << move_to(0,0)
            << color(171,230,170)
            << box(XX-1, YY-1);
}



