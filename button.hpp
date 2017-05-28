//csak a beallitohoz kell
//meret, pozicio, belso "felirat"

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <string>
#include <functional>

struct funktor
{
    int c;
    int d;
    funktor(){};
    funktor(int &_c, int &_d);
    void operator()();
};

class Button : public Widget
{
protected:
    std::string s;  //gomb felirata
    bool pressed;   //meg van-e nyomva a gomb - kindof selected a tobbinel

    //std::function<void()> kacsa;
    funktor kacsa;


public:
    Button();
    Button(int x, int y, std::string _S);
    Button(int x, int y, int sx, int sy, std::string _s, /*std::function<void()>*/ funktor k);

    virtual void Action();

    virtual void Draw() const;
    virtual void Handle(genv::event ev);
    bool isPressed() const;

    void setX(int x);




};



#endif //BUTTON_HPP
