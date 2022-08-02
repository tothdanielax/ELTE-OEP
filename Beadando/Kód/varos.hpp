#pragma once

#include <string>
#include <iostream>


#include "turista.hpp"
#include "allapot.hpp"

using namespace std;

class Varos {

    static int year; // 

    private:

        int bevetel; // azért nem = 0, mert csinálok settert (később fejleszthetőbb, ha más lesz a kezdő bevétele városoknak)

        Allapot allapot;

        Japan japan;
        Modern modern;
        Mas mas;

    public:

       void setBevetel(int b) { bevetel = b; }
       int getBevetel() { return bevetel; }

       void setAllapot(int p) { allapot.setPont(p); }
       int getAllapotP() { return allapot.getPont(); }
       string getAllapotN() { return allapot.getName(); }

       void getTurista() {

           cout << "\n" << year << ". Ev" << endl;
           
           cout << "Japan turistak:\n";
           cout << "\t Vart: " << japan.getVart() << endl;
           cout << "\t Erkezett: " << japan.getErk() << endl;

           cout << "Modern turistak:\n";
           cout << "\t Vart: " << modern.getVart() << endl;
           cout << "\t Erkezett: " << modern.getErk() << endl;

           cout << "Mas turistak:\n";
           cout << "\t Vart: " << mas.getVart() << endl;
           cout << "\t Erkezett: " << mas.getErk() << endl;

           year++;
       }

       void latogatas(int japanok, int modernek, int masok) {

            japan.beolvasas(japanok, allapot);
            modern.beolvasas(modernek, allapot);
            mas.beolvasas(masok, allapot);

            bevetel = (japan.getErk() + modern.getErk() + mas.getErk()) * 100'000;

            int osszRontas = modern.allapotRontas() + mas.allapotRontas();
            
            allapot.setPont(allapot.getPont() - osszRontas);
           
       }

        void javitas() {

            if(bevetel > 1'000'000'000) {
                int javpont = (bevetel - 1E9) / 20'000'000;

                allapot.setPont(allapot.getPont() + javpont);
            }

            bevetel = 0;

        }

        // TEST -> private
        int getJapanErk() {
            return japan.getErk();
        }

        int getModernErk() {
            return modern.getErk();
        }

        int getMasErk() {
            return mas.getErk();
        }

};
