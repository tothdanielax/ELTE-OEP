#include <fstream>
#include <iostream>

#include "enor.hpp"

using namespace std;

int main() {
    try {
        Enor x("inp.txt"); 

        string nev;
        
        Status st;
        Versenyzo versenyzo;

        x.read(versenyzo, st);
        
        while(st == norm && 5000 >= versenyzo.osszido) {
            x.read(versenyzo, st);
        }

        float max_atlag = versenyzo.atlag;
        x.read(versenyzo, st);
        
        while(st == norm) {
            if(versenyzo.atlag > max_atlag) {
                max_atlag = versenyzo.atlag;
                nev = versenyzo.nev;
            }
            x.read(versenyzo, st);
        }

        cout << nev << " " << max_atlag << endl;
    } catch (Enor::FileErrorException ex) {
        cerr << "File open error!" << endl;
    }
}