#ifndef LIST_HPP
#define LIST_HPP

#include "widget.hpp"

#include <string>
#include <vector>



///szinhez kell, ha megbuknek kibovitem a tobbi widgetre is
class colour
{
protected:
    int pr;
    int pg;
    int pb;

public:
    colour(int r, int g, int b);
    int r() const;
    int g() const;
    int b() const;
};


///a listaelemek felirata
class ListObject
{
public:
    ListObject(std::string _s);
    std::string s;
    bool selected;
    std::string getTitle() const; ///BEADAS UTAN
};


///listaelemek rajzolasa
class ListCell : public Widget
{
private:
    ListObject * object;
    colour boxColour;


public:
    ListCell(int x, int y, int sx, int sy, ListObject * _obj);
    virtual void Draw() const;
    virtual void Handle(genv::event ev);

    void setObject(ListObject * _o);
    void setCellBackground(genv::event ev, bool _selected);
    void setTitle(std::string _title);
    std::string getTitle() const; ///BEADAS UTAN
};

///maga a lista
class List : public Widget
{
private:
    int scrollOffset = 0;
    std::vector<ListObject *> objects;
    std::vector<ListCell *> cells;
    int selectedIndex = -1;
    int absIndex = 0;

public:
    List(int x, int y, int sx, int sy, std::vector<std::string> obj);
    virtual void Draw() const;
    virtual void Handle(genv::event ev);

    void init();
    void initWithArray(std::vector<std::string > _objects);
    void addObject(std::string title);
    void Scroll(int offset);

    std::vector<ListObject *> getObjects() const;
    std::string getSelectedObject() const;
    std::vector<std::string> getTitles() const;
    int getSelectedIndex() const;

    int getObjectsSize() const;

    void eraseObject();

};



#endif // LIST_HPP
