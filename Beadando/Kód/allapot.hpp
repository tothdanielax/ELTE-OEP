#pragma once

#include <string>

using namespace std;

class Allapot {

    private:

        int pont;
        string name;
    
    public:

        void setPont(int p) {

            if(p > 99) {
                pont = 99;
            } else if(p < 1) {
                pont = 1;
            } else {
                pont = p;
            }

            if(pont > 67) {
                name = "jo_allapotu";
            } else if(pont > 33) {
                name = "atlagos";
            } else {
                name = "lepusztult";
            }

        }

        int getPont() { return pont; }
        string getName() { return name; }
        
};