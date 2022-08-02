#pragma once

#include "objektum.hpp"

#include <string>

using namespace std;

class Megfigyeles {
    public:
        string datum;
        double tomeg;
        double tav;
        Objektum* obj;

        Megfigyeles(Objektum* o, string d, double to, double ta):obj(o),datum(d),tomeg(to),tav(ta){}
        double Tomeg(){return (tomeg * obj->TomegSzorzo());}
        double Tav(){return (tav * obj->TavSzorzo());}
};