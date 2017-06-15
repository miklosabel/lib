#include "window.hpp"
#include <iostream>
#include <algorithm>

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

    l = new List(300,100,140,87, obj);
    percek = new Szambe(145,20,-1,60,00);
    orak = new Szambe(70,20,-1,24,00);
    hosszok = new Szambe(220,20,-1,500,10);


    t = new Textbox(70, 45, 10, 4+gout.cdescent()+gout.cascent(),"");
    beletolt = new Button(70,100,"Beletolt");
    beletolt -> setCallBack([&]()
                        {
                            Fill();
                            cout << endl;
                        });


//    kivesz = new Button(70,130,"Kiir");
//    kivesz->setCallBack([&]()
//                        {
//                            Kiir();
//                        });

//    meret = new Button(70,160,"Meret");
//    meret->setCallBack([&]()
//                        {
//                            cout << l->getObjectsSize()<< endl;
//                        });

    torol = new Button(70,190,"Torol");
    torol->setCallBack([&]()
                       {
                            l->eraseObject();
                            musorok.erase(musorok.begin()+l->getSelectedIndex());
                       });


    s = new Statictext(70,220,"");
    pipa = new Checkbox(70,250,20,20);

    w.push_back(orak);
    w.push_back(percek);
    w.push_back(hosszok);
    w.push_back(s);
    w.push_back(l);
    w.push_back(t);
    w.push_back(beletolt);
//    w.push_back(kivesz);
//    w.push_back(meret);
    w.push_back(torol);
    w.push_back(pipa);
}

bool sortByName(const musor &lhs, const musor &rhs) { return lhs.kezdespercben < rhs.kezdespercben; }

///probalkozas a megfelelo mukodesre
void App::Fill()
{
    musor m;
    m.cim = t->getTitle();
    m.ora = orak->getNum();
    m.perc = percek -> getNum();
    m.hossz = hosszok -> getNum();
    m.kezdespercben = m.ora*60 + m.perc; // kell hogy osszehasonlithatoak legyenek az idok
    bool isMusorExist = false;

///Utkozesvizsgalat -- BEADAS UTAN------------------------------------------------
    for (unsigned int i = 0; i < musorok.size(); i++)
    {
        if (musorok[i].kezdespercben <= m.kezdespercben)
        {
            if(musorok[i].kezdespercben+musorok[i].hossz >= m.kezdespercben) isMusorExist = true;
        }
        else if (musorok[i].kezdespercben >= m.kezdespercben)
        {
            if(musorok[i].kezdespercben <= m.kezdespercben+m.hossz) isMusorExist = true;
        }
    }

    if (!isMusorExist) musorok.push_back(m);

///sorbarendezes --- BEADAS UTAN--------------------------------------------
    sort(musorok.begin(), musorok.end(), sortByName);
///----------------------------------------------------------------------------
    this -> updateLength();
}

//void App::Kiir()
//{
//    for (unsigned int i=0;i<musorok.size();i++)
//    {
//        cout << l->getTitles()[i] <<" \t"<< musorok[i].cim << endl;
//    }
//    cout << endl;
//}

///BEADAS UTAN-------------------------------------------------------


void App::updateLength()
{
    vector<string> feltolto;
    for (musor temp : musorok)
    {
        feltolto.push_back(temp.cim + " " + to_string(temp.hossz));
    }
    l->initWithArray(feltolto);
}


///--------------------------------------------------------------------
//    ///vektorelemek sorbarendezese
//    sort(objects.begin(), objects.end());
