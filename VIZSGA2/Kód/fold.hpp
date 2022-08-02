#pragma once 

#include "allomas.hpp"
#include <vector>

class Allomas;

using namespace std;


class Fold {
    private:
        static Fold* _instance;
    public:
        vector<Allomas*> allomasok;
        
        static Fold* instance() {
            if(_instance == nullptr) {
                _instance = new Fold();
            }
            return _instance;
        }
        static void destroy() {
            if(_instance != nullptr) {
                delete _instance;
            }
            _instance = nullptr;
        }

        void Uzembe(Allomas* a) {
            allomasok.push_back(a);
        }        
};