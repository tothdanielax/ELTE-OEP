#pragma once

#include "megfigyeles.hpp"
#include <string>
#include <vector>

using namespace std;

class Allomas {
    public:
        string azon;
        vector<Megfigyeles*> megf;
        Allomas(string a):azon(a){}
        
        void Eszlel(Objektum* o, string d, double to, double ta) {
            megf.push_back(
                        new Megfigyeles(o,d,to,ta)
                    );
        }

};