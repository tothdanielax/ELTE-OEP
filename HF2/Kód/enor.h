#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Enor {
    private:
        enum Status { 
            abnorm,
            norm 
        };

        int e;
        ifstream f;
        Status st;

        void read() {
            if ( f >> e ) {
                st = norm;
            } else {
                st = abnorm;
            }
        }

    public:
        class FileErrorException : public exception { };

        Enor( const string& fn ) {
            f.open( fn );
            if ( f.fail() ) {
                throw FileErrorException();
            }
        }

        void first() {
            read();
        }

        void next() {
            read();
        }

        int current() const {
            return e;
        }

        bool end() const {
            return st == abnorm;
        }
};