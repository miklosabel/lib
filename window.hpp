#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include "widget.hpp"

#include "szambe.hpp"
#include "kival.hpp"
#include "textbox.hpp"

class Window
{
    protected:
        std::vector<Widget *> w;
    public:
        virtual void Fuss();
};


class App : public Window
{
    protected:
        ///minden ami az adott feladathoz szukseges
        Szambe * szambe;
        Szambe * s2;
        Kival * kival;
        Statictext * st;
        Statictext * st2;
        Textbox * t;
        Button * b;


    public:
        App();
};





#endif // WINDOW_HPP


