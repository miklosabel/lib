#include "window.hpp"
#include <iostream>

using namespace genv;


void Clear();

const int XX = 600;
const int YY = 600;

void Window::Fuss()
{
    gout.open(XX,YY);
    event ev;

    Clear();

    for (unsigned int i = 0; i < w.size(); i++) w[i] -> Draw();
    while( gin >> ev && ev.keycode != key_escape )
    {
        ///feladatok: fokuszalt widgetek kezelese
        Clear();

        for (unsigned int i = 0; i < w.size(); i++)
        {
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

App::App()
{
    szambe = new Szambe(20,20,20,110,23);
    s2 = new Szambe(120,20,20,110,105);
    //kival = new Kival(20,60,4,3);
    st = new Statictext(70, 100, "anyad");
    st2 = new Statictext(70, 150, "teanyad");
    t = new Textbox(70, 200, 10, 4+gout.cdescent()+gout.cascent(),"");
    b = new Button(400,100,"Gomb");
    b -> setCallBack([&]()
     {
        std::cout<<"gomb megnyomva\n";
     });

    w.push_back(b);
    w.push_back(s2);
    w.push_back(t);
    w.push_back(st2);
    w.push_back(st);
    w.push_back(szambe);
    //w.push_back(kival);
}
