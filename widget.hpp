#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <functional>
#include "graphics.hpp"

//struct funktor
//{
//    int c;
//    int d;
//    funktor(){};
//    funktor(int &_c, int &_d);
//    void operator()();
//};

class Widget
{
protected:
    int itsX;
    int itsY;
    int sizeX;
    int sizeY;
    std::function<void()> callback;
    ///lambdafv azert itt, mert igy minden widget tipust tud majd kezelni
    //    funktor kacsa;

public:
    Widget();                 //default konstruktor
    Widget(int x, int y);
    Widget(int x, int y, int sx, int sy);

    virtual void Draw() const;  //const mert nem akar/szabadneki valtoztatni semmin
    virtual void DrawContour(bool clicked) const;

    virtual void Handle(genv::event ev);
    void HandleSelected(genv::event ev);

    virtual bool Selected(int mouseX, int mouseY) const;

    int getY() const; //statictext hasznalja
    void setY(int y);

    void getter(int i) const;   //ezzel a main-bol is lekerdezhetjuk a widgetek kozos mezoit
                                //i miatt for ciklusban erdemes hasznalni

    ///lambda
    template<typename T>
    void setCallBack(T&& _fn)
    {
        callback = _fn;
    }
};

#endif //WIDGET_HPP
