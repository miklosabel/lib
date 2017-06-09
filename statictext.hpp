#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <string>

//csak magat a szoveget irja ki
//nincs szovegdoboz
//csak szoveget rajzol ki, szamot nem!! (jotanacs magamnak)

class Statictext : public Widget
{
protected:
    std::string s;

public:
    Statictext();
    Statictext(int x, int y, std::string _s);
    Statictext(int x, int y, int sx, int sy, std::string _s);

    virtual void Draw() const;
    virtual void Handle(genv::event ev);    //ki van-e valasztva("ra van-e kattinva")

    void setText(std::string text);  //setter a kiirando ertekhez
                                //megvaltoztatja a mereteket is
    std::string getText() const;


};


#endif ///STATICTEXT_HPP
