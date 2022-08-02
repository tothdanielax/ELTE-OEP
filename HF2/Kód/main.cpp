#include <iostream>
#include <fstream>

#include "enor.h"

using namespace std;

int main() {
    try {
        // input
        Enor e( "input.txt" );

        // Max-ot első elemhez rendelem, majd hasonlítgatom a current-hez. 
        // Ha current > max, akkor a current lesz az új max és a dbszámot előről kezdem.
        // Ha current == max, akkor dbszámot növelem.
        e.first();
        int max = e.current();
        int max_count = 1;

        while( !e.end() ) {
            if( max < e.current() ) {
                max = e.current();
                max_count = 1;
            } else if( max == e.current() ) {
                max_count++;
            }
            e.next();
        }
        
        // output
        cout << "Max: " << max << endl;
        cout << "Occurence of max: " << max_count << endl;
    } catch ( Enor::FileErrorException ex ) {
        cerr << "Invalid file name!\n";
    }
}