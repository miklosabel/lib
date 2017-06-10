#ifndef CHECKBOX
#define CHECKBOX

#include "widget.hpp"
#include "graphics.hpp"

class Checkbox : public Widget
{
private:
    bool checked;
public:
    Checkbox(int x, int y, int sx, int sy);
    virtual void Draw() const;
    virtual void Handle(genv::event ev);
    bool isChecked() const;
};

#endif // CHECKBOX
