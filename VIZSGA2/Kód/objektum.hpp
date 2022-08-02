#pragma once

#include <string>
#include <cmath>

using namespace std;

class Objektum {
    public:
        string azon;
        Objektum(string a) : azon(a){}
        virtual double TomegSzorzo() const = 0;
        virtual double TavSzorzo() const = 0;
        virtual bool IsAszteroida() const {return false;}
};

class Aszteroida : public Objektum {
    public:
        Aszteroida(string a) : Objektum(a){}
        double TomegSzorzo() const override {return (pow(10,6));}
        double TavSzorzo() const override {return (pow(10,3));}
        bool IsAszteroida() const override {return true;}
};

class Nap : public Objektum {
    public:
        Nap(string a) : Objektum(a){}
        double TomegSzorzo() const override {return (1.98*pow(10,30));}
        double TavSzorzo() const override {return (9.5*pow(10,12));}
};

class Feketelyuk : public Objektum {
    public:
        Feketelyuk(string a) : Objektum(a){}
        double TomegSzorzo() const override {return (1.98*pow(10,30));}
        double TavSzorzo() const override {return (9.5*pow(10,20));}
};
