#include <iostream>
#include "complex.h"
#include "menu.h"

using namespace std;


int main() {
    // input

    float a1, a2;
    float b1, b2;

    cout << "Give me the 1st Complex number's real, then imaginary part!" << endl;
    cin >> a1 >> a2;
    cout << "Give me the 2nd Complex number's real, then imaginary part!" << endl;
    cin >> b1 >> b2;

    // comp

    Comp a (a1, a2);
    Comp b (b1, b2);
    
    // menu 
    
    menu (a, b);

    return 0;
}

