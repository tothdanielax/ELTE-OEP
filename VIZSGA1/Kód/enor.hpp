#pragma once

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Status {
    abnorm,
    norm
};

struct Versenyzo {
    string csapat;
    string nev;
    float osszido;
    float atlag;
};

struct Nap {
    string megnevezes;
    float ido;
};

class Enor {
    private:
        ifstream x;
    public:
        class FileErrorException : public exception {};

        Enor(const string &fn);

        void read(Versenyzo &versenyzo, Status &st);
};

