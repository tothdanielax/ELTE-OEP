#pragma once

#include <string>

#include "allapot.hpp"

using namespace std;

class Turista {

    protected:

        int vartTurista;
        int erkTurista;

    public:

        int getVart() { return vartTurista; }
        int getErk() { return erkTurista; }

        virtual void beolvasas(int t, Allapot allapot) = 0;
        virtual int allapotRontas() { return 0; }

};

class Japan : public Turista {

    public:

        void beolvasas(int t, Allapot allapot) override {
            
            vartTurista = t;
            string a = allapot.getName();

            if(a == "jo_allapotu") {
                erkTurista = t * 1.2;
            } else if(a == "atlagos") {
                erkTurista = t;
            } else {
               erkTurista = 0;
            }
        }

};

class Modern : public Turista {

    public:

        void beolvasas(int t, Allapot allapot) override {
                    
            vartTurista = t;
            string a = allapot.getName();


            if(a == "jo_allapotu") {
                erkTurista = t * 1.3;
            } else if(a == "atlagos") {
                erkTurista = t * 1.1;
            } else {
                erkTurista = t;
            }
        }

        int allapotRontas() override { return erkTurista/100; }

};

class Mas : public Turista {

    public:

        void beolvasas(int t, Allapot allapot) override {
                    
            vartTurista = t;
            string a = allapot.getName();


            if(a == "jo_allapotu") {
                erkTurista = t;
            } else if(a == "atlagos") {
                erkTurista = t * 1.1;
            } else {
                erkTurista = t;
            }
        }

        int allapotRontas() override { return erkTurista/50; }

};