#ifndef KIVAL_HPP_INCLUDED
#define KIVAL_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "statictext.hpp"
#include <vector>


class Kival : public Widget {
    protected:
        bool selected;  //adott Kival widget ki van-e jelolve
        int pressed;    //barmelyik tagja ki van-e jelolve
        int elemszam;   
        int random;     //ezek miatt lesznek kulonbozo elemek a kivalasztoban
        std::vector<Statictext *> stvector;
        int gorget; //gorgetes hatarait adja
    public:
        Kival( int x, int y, int elszam, int ran );

        void Scroll(int direction);
        virtual void Draw() const;                    
        virtual void Handle(genv::event ev);  
};


#endif // KIVAL_HPP