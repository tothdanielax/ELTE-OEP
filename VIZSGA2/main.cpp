#include "templates.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

int count = 0;
bool fail = false;

class FoldContainer {
public:
    ~FoldContainer() {
        Fold::destroy();
    }
} FC;

void test_Megfigyeles(Objektum* o) {
    Megfigyeles* m = new Megfigyeles(o, "1973", 10, 30);

    check<std::string>(m->datum, "1973",
        "Megfigyeles datum hibas erteket ad vissza.");
    check<std::string>(m->obj->azon, o->azon,
        "Megfigyeles obj->azon hibas erteket ad vissza.");
    check<double>(m->tav, 30,
        "Megfigyeles tav hibas erteket ad vissza.");
    check<double>(m->tomeg, 10,
        "Megfigyeles tomeg hibas erteket ad vissza.");
    delete m;
}

void test_Allomas(std::string nev, Objektum* o) {
    Allomas* a = new Allomas(nev);
    check<std::string>(a->azon, nev,
        "Allomas azon hibas erteket ad vissza.");
    check<unsigned int>(a->megf.size(), 0,
        "Allomas megf.size() hibas erteket ad vissza eszleles elott.");
    a->Eszlel(o, "2022", 40, 50);
    check<unsigned int>(a->megf.size(), 1,
        "Allomas megf.size() hibas erteket ad vissza eszleles utan.");
    assert(a->megf.size() > 0);
    check<std::string>(a->megf[0]->obj->azon, o->azon,
        "Allomas megf[0]->obj->azon hibas erteket ad vissza.");
    delete a;
}

bool test() {
    FoldContainer fc;

    std::cout << "--Objektumok--\n";

    test_ObjektumGetters<Aszteroida>("asz0", 1e3, 1e6, true);
    test_ObjektumGetters<Nap>("nap0", 9.5e12, 1.98e30, false);
    test_ObjektumGetters<Feketelyuk>("fly0", 9.5e20, 1.98e30, false);

    std::cout << "--Megfigyeles--\nEddigi tesztek szama: " << count << '\n';

    Objektum* asz4 = new Aszteroida("asz4");
    test_Megfigyeles(asz4);

    std::cout << "--Allomas--\nEddigi tesztek szama: " << count << '\n';

    Objektum* asz5 = new Aszteroida("asz5");
    test_Allomas("all2", asz5);

    std::cout << "--Fold--\nEddigi tesztek szama: " << count << '\n';

    Fold* f = Fold::instance();

    assert(Fold::instance());
    check<Fold*>(Fold::instance(), Fold::instance(),
        "Fold instance() kulonbozo ertekeket ad vissza.");

    check<unsigned int>(f->allomasok.size(), 0,
        "Fold allomasok.size() hibas erteket ad vissza.");
    f->Uzembe(new Allomas("all1"));
    check<unsigned int>(f->allomasok.size(), 1,
        "Fold allomasok.size() hibas erteket ad vissza.");
    assert(f->allomasok.size() > 0);
    check<std::string>(f->allomasok[0]->azon, "all1",
        "Fold allomasok[0]->azon hibas erteket ad vissza.");
    
    return !fail;
}

int main() {
    try
    {
        if (test()) {
            std::cout << "Ok\n";
            return 0;
        }
        else {
            std::cout << "Failed\n";
            return 1;
        }
    }
    catch(...)
    {
        std::cout << "Error\n";
        return 1;
    }
}

