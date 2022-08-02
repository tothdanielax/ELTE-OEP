#pragma once

class Comp {
    private:
        float x;
        float y;

    public:
        Comp (float a, float b);
        Comp Add (Comp a, Comp b);
        Comp Sub (Comp a, Comp b);
        Comp Mul (Comp a, Comp b);
        Comp Div (Comp a, Comp b);
        void print ();
};