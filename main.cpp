///======================================================================================
///szambeallito mukodik csak.
///kivalaszto Draw() fv-be nem fut be sehogy sem, 6 ora alatt nem jottem ra miert.
///azert nem egyebkent, mert nem volt egy elem inicializalva a konstuktorban
///illetve veletlenul feluldefinialtam a widget Draw()jat ettpl nem futott be abba (nyilvan)
///======================================================================================

#include <iostream>
#include <vector>
#include <string>
#include <exception>

#include "window.hpp"

using namespace std;
using namespace genv;

int main()
{
//     int a = 5;
//     int b = 10;
//
//    funktor f(a, b); //funktor letrehozas (ugyanazt csinalja mint a lambda)
//
//    mindent ahol function van ki kell cserelni template parameterre hogy mukodjon lambdaval es funktorral is

//    Button * b1 = new Button(20,50, 30,20,"gg", /*lambda ide is irhato,*/ f);

//    [&a,&b](){
//                b=a;
//                cout<<"b:"<<b<<endl;
//             } lambda fv
//
//    gout.open(XX,YY);
//    Clear();
//
//    vector<Widget *> w;

    App * A = new App();
    A -> Fuss();

    return 0;
}






