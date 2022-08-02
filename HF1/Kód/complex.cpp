#include <iostream>
#include "complex.h"
using namespace std;



Comp::Comp (float a, float b) {
    x = a;
    y = b;
}

Comp Comp::Add (Comp a, Comp b) {
    return Comp (a.x + b.x, a.y + b.y);
}

Comp Comp::Sub (Comp a, Comp b) {
    return Comp (a.x - b.x, a.y - b.y);
}

Comp Comp::Mul (Comp a, Comp b) {
    return Comp (a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

Comp Comp::Div (Comp a, Comp b) {
    if (b.x != 0 || b.y != 0) {
        return Comp ((a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y), (a.y * b.x - a.x * b.y) / (b.x * b.x + b.y * b.y));
    } else {
        cerr << "Not divisible. B.x and b.y equals 0." << endl;
    }
}

void Comp::print () {
    cout << x << " +- " << y << "i" << endl;
}
