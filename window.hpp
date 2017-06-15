#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <utility>

#include "widget.hpp"
#include "szambe.hpp"
#include "textbox.hpp"
#include "list.hpp"
#include "checkbox.hpp"

class Window
{
    protected:
        std::vector<Widget *> w;
    public:
        virtual void Fuss();
};
///BEADAS UTAN-------------------------
struct musor
{
    std::string cim;
    int ora;
    int perc;
    int kezdespercben;
    int hossz;
};
///--------------------------------------

class App : public Window
{
private:
    std::vector<musor> musorok;

protected:
        ///minden ami az adott feladathoz szukseges

    Szambe * percek;
    Szambe * orak;
    Szambe * hosszok;
    Textbox * t;
    Button * beletolt;
    Button * kivesz;
    List * l;
    Statictext * s;
    Button * meret;
    Button * torol;

    Checkbox * pipa;



public:
    App();
    void Fill();
    void Kiir();
    void updateLength();
};





#endif // WINDOW_HPP


