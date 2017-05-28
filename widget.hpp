#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

class Widget
{
protected:
    int itsX;
    int itsY;
    int sizeX;
    int sizeY;
    bool focused; //barmely widget erzekeli ha folotte van az eger

public:
    Widget();                 //default konstruktor
    Widget(int x, int y);       //kell egy ilyen is mert igazabol
                                //a beadando felenel jottem ra hogy 
                                //csak ezt hasznalnam, ha meg lenne irva
    Widget(int x, int y, int sx, int sy);

    virtual void Draw() const;  //const mert nem akar/szabadneki valtoztatni semmin
    virtual void Handle(genv::event ev);
    
    void setFocus(int mouseX, int mouseY);  //allandoan ellenprizni kell hogy folotte van-e az eger,
                                            //ezert a leszarmazottak handle-ben fogjak hivni
    virtual bool isFocused() const; //getter a focusedhoz

    virtual bool is_selected(int mouseX, int mouseY) const;

    int getY() const; //statictext hasznalja
    void setY(int y);

    void getter(int i) const;   //ezzel a main-bol is lekerdezhetjuk a widgetek kozos mezoit
                                //i miatt for ciklusban erdemes hasznalni
    



};

#endif //WIDGETS_HPP