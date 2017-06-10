#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "statictext.hpp"
#include <string>

class Textbox : public Widget
{
protected:
    std::string s;
    bool clicked; //focused ! egerkattintast tarolja

public:
    Textbox();
    Textbox(int x, int y);  //uresen megadhato textbox
    Textbox(int x, int y, std::string _s);  //szoveggel megadhato textbox
    Textbox(int x, int y, int sx, int sy, std::string _s); //fullextra +10 millioert

    virtual void Draw() const;
    virtual void Handle(genv::event ev);

    std::string getTitle();

    /// bool isSelected() const;
    /// void setSelected(bool b);

};


#endif //TEXTBOX
