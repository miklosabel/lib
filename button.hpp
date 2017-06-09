//csak a beallitohoz kell
//meret, pozicio, belso "felirat"

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <string>


class Button : public Widget
{
protected:
    std::string s;  //gomb felirata
    bool pressed;   //meg van-e nyomva a gomb - kindof selected a tobbinel


public:
    Button();
    Button(int x, int y, std::string _s);
    Button(int x, int y, int sx, int sy, std::string _s);

    virtual void Draw() const;
    virtual void Handle(genv::event ev);



    bool isPressed() const;
    void setX(int x);



};



#endif //BUTTON_HPP
