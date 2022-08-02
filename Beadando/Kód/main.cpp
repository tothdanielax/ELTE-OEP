//Author:    Tóth Zsolt Dániel
//Date:      2022.06.08.
//Task:      6 

#include <fstream>
#include <stdexcept>

#include "varos.hpp"

using namespace std;

int Varos::year = 1;

int main() {

    fstream f;
    
    f.open("input.txt");

    if(f.fail()) {
        throw invalid_argument("Invalid input file name.");
    }

    int a, ev;
    f >> a >> ev; 

    Varos varos;
    varos.setAllapot(a);
    varos.setBevetel(0);

    int b1, b2, b3; // buffer

    while(f >> b1 >> b2 >> b3) {

        varos.latogatas(b1, b2, b3);
        varos.getTurista();
        cout << "Allapot: " << varos.getAllapotP() << " " << varos.getAllapotN() << endl;
        cout << "Bevetel: " << varos.getBevetel() << "\n\n";

        varos.javitas();
    }

    f.close();
}
