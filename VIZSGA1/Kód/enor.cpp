#include "enor.hpp"
#include <sstream> 

using namespace std;

Enor::Enor(const string &fn) {
    x.open(fn);
    if(x.fail()) {
        throw FileErrorException();
    }
}

void Enor::read(Versenyzo &versenyzo, Status &st) {
    string line;

    if(getline(x, line)) { 
        st = norm; 
        
        istringstream iss(line);

        iss >> versenyzo.csapat >> versenyzo.nev >> versenyzo.osszido;

        versenyzo.atlag = 0;
        int napokszama = 0;

        Nap nap;

        while(iss >> nap.megnevezes >> nap.ido) {
            versenyzo.atlag = versenyzo.atlag + nap.ido;
            napokszama++;
        }

        versenyzo.atlag = versenyzo.atlag / napokszama;
    } else {
        st = abnorm; 
    }
}