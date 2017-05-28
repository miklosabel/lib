#ifndef SZAMBE_HPP_INCLUDED
#define SZAMBE_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "statictext.hpp"
#include "button.hpp"
#include <vector>
#include <string>

class Szambe : public Widget
{
protected:
    int max;
    int min;    //intervallumok
    int num;    //tarolt szam
    Statictext * st;    //szamot kiiro szovegmezo
    std::vector<Button*> buttonvector;
    bool selected; //maga a widget ki van-e valasztva

public:
    Szambe();
    Szambe(int x, int y, int _min, int _max, int _num);

    virtual void Draw() const;
    virtual void Handle(genv::event ev);
};



#endif //SZAMBE_HPP