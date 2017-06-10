#include "list.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace genv;

extern const int cellSize = 17;

///colour fv-ek
colour::colour(int r, int g, int b) : pr(r), pg(g), pb(b) {}
int colour::r() const {return pr;}
int colour::g() const {return pg;}
int colour::b() const {return pb;}

///ListObject fuggvenyek
ListObject::ListObject(string _s) : s(_s), selected(false) {}

///ListCell fuggvenyek
ListCell::ListCell(int x, int y, int sx, int sy, ListObject * _obj)
    : Widget(x,y,sx,sy),
    object(_obj),
    boxColour(colour(81,109,107)) {sizeY = cellSize;}

void ListCell::Draw() const
{
    ///keret
    if (object -> selected) gout << color(148,255,135);
    else gout << color(boxColour.r(),boxColour.g(),boxColour.b());

    gout<< move_to(itsX, itsY)
        << box(sizeX,sizeY);

    ///szoveg
    gout<< move_to(itsX+5, itsY+gout.cascent()+2)
        << color(240,240,240)
        << text(object -> s);
}

void ListCell::Handle(event ev)
{
    setCellBackground(ev, Selected(ev.pos_x, ev.pos_y));
}
///eger felette->lilas szin, egyebkent alapszin
void ListCell::setCellBackground(event ev, bool _selected)
{
    if (_selected) this -> boxColour = colour(150,185,255);
    else this -> boxColour = colour(81,109,107);
}


void ListCell::setTitle(string _title)
{

}

void ListCell::setObject(ListObject * _o)
{
    object = _o;
}

///List fuggvenyek
List::List(int x, int y, int sx, int sy, vector<string> obj)
    : Widget(x,y,sx,sy)
{
    if (obj.size() > 0)
    {
        for(string s : obj)
        {
            ListObject * lo = new ListObject(s);
            objects.push_back(lo);
        }
    }
    this -> init();
}

void List::Draw() const
{
    gout<< move_to(itsX, itsY)
        << color(81,109,107)
        << box(sizeX, sizeY);

    for (unsigned int i = 0; i < cells.size(); i++) cells[i] -> Draw();
}

void List::Handle(event ev)
{
    this -> HandleSelected(ev);
    for (unsigned int i = 0; i < cells.size(); i++) cells[i] -> Handle(ev);

    if (ev.type == ev_mouse && this -> Selected(ev.pos_x, ev.pos_y))
    {
        if (ev.button == btn_wheeldown && objects.size() > itsY/cellSize)
        {
            if (scrollOffset+itsY/cellSize < this -> objects.size())
            {
                scrollOffset++;
            }
            Scroll(scrollOffset);
        }
        if (ev.button == btn_wheelup && objects.size() > itsY/cellSize)
        {
            if (scrollOffset > 0)
            {
                scrollOffset--;
            }
            Scroll(scrollOffset);
        }


        absIndex = (ev.pos_y - itsY)/cellSize;
        int relativeIndex = absIndex + scrollOffset;
        if (ev.button == btn_left)
        {
            for (int i = 0; i < objects.size(); i++) objects[i]->selected = false;
            objects[relativeIndex] -> selected = true;
        }
    }
}



void List::init()
{
    cells.clear();
    if (objects.size() > 0)
    {
        int maxSize = objects.size();
        if (maxSize > itsY/cellSize) maxSize = itsY/cellSize;
        for (int i = 0; i < maxSize; i++)
        {
            ListCell * lc = new ListCell(this->itsX, this->itsY+i*cellSize, this->sizeX, this->sizeY, objects[i]);
            cells.push_back(lc);
        }
    }
}

void List::initWithArray(vector<string> _objects)
{
    objects.clear();
    if (_objects.size() > 0)
    {
        for(string s : _objects)
        {
            ListObject * lo = new ListObject(s);
            objects.push_back(lo);
        }
    }
    this -> init();
}

void List::addObject(string title)
{
    ListObject * newObj = new ListObject(title);
    objects.push_back(newObj);
    this -> init();
}

void List::Scroll(int offset)
{
    if (cells.size() > 0)
    {
        for (int i = offset; i < offset + sizeY/cellSize; i++)
        {
            cells[i-offset] -> setObject(objects[i]);
        }
    }
}

vector<ListObject *> List::getObjects() const {return objects;}

vector<string> List::getTitles() const
{
    vector<string> titles;
    for (ListObject * object : objects) titles.push_back(object->s);
    return titles;
}

string List::getSelectedObject() const
{
    for (ListObject * obj : objects)
    {
        if (obj -> selected) return obj->s;
    }
    return "none_selected";
}

int List::getSelectedIndex() const
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->selected) return i;
    }
    return -1;
}

int List::getObjectsSize() const
{
    return objects.size();
}

