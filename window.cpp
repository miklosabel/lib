#include "window.hpp"
#include <iostream>

using namespace genv;
using namespace std;


void Clear();

const int XX = 600;
const int YY = 600;

void Window::Fuss()
{
    gout.open(XX,YY);
    event ev;

    Clear();

    for (unsigned int i = 0; i < w.size(); i++) w[i] -> Draw();
    do {
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
    } while( gin >> ev && ev.keycode != key_escape );
}

void Clear()
{
    gout<< move_to(0,0)
        << color(171,230,170)
        << box(XX-1, YY-1);
}

App::App()
{
    vector<string> obj;
    l = new List(300,100,100,87, obj);
    percek = new Szambe(145,20,-1,31,59);
    orak = new Szambe(70,20,-1,24,13);


    t = new Textbox(70, 45, 10, 4+gout.cdescent()+gout.cascent(),"");
    beletolt = new Button(70,100,"Beletolt");
    beletolt -> setCallBack([&]()
                        {
                            Fill();
                        });

    kivesz = new Button(70,130,"Kiir");
    kivesz->setCallBack([&]()
                        {
                            Kiir();
                        });

    meret = new Button(70,160,"Meret");
    meret->setCallBack([&]()
                        {
                            cout << l->getObjectsSize()<< endl;
                        });

    s = new Statictext(70,200,"");

    w.push_back(orak);
    w.push_back(s);
    w.push_back(l);
    w.push_back(beletolt);
    w.push_back(kivesz);
    w.push_back(t);
    w.push_back(percek);
    w.push_back(meret);
}

///probalkozas a megfelelo mukodesre
void App::Fill()
{
    l->addObject(t->getTitle() + " (" +to_string(percek->getNum()) + ")" );
}

void App::Kiir()
{
    s->setText(l->getSelectedObject());
}
