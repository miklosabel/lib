#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
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


class App : public Window
{
    protected:
        ///minden ami az adott feladathoz szukseges

        Szambe * percek;
        Szambe * orak;
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
};





#endif // WINDOW_HPP


