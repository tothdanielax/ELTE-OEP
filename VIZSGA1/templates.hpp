#ifndef TEST_TEMPLATES_HPP
#define TEST_TEMPLATES_HPP

/*ITT INCLUDE-OLD A HEADER FÁJLJAID!!!*/

#include <type_traits>
#include <cassert>
#include <sstream>
#include <string>
#include <iostream>
#include <cxxabi.h>

extern int count;
extern bool fail;

void check(bool value, std::string message) {
    ++count;
    if (!value) {
        fail = true;
        std::cout << message << "\nTeszt: " << count << '\n';
    }
}

template<typename T>
void check(T value, T golden, std::string message) {
    ++count;
    if (value != golden) {
        fail = true;
        std::cout << message << "\nElvart ertek: " << golden << ";\tKapott ertek: " << value << "\nTeszt:" << count << '\n';
    }
}

template<typename T>
std::string getType(T val) {
    char* c = abi::__cxa_demangle(typeid(val).name(), 0, 0, nullptr);
    std::string res(c);
    free(c);
    return res;
}

std::string operator+ (const std::string& lhs, const std::string& rhs) {
    std::ostringstream oss;
    oss << lhs << rhs;
    return oss.str();
}

template<typename T>
void test_ObjektumGetters(std::string nev, double tavSz, double tomSz, bool aszt) {
    static_assert(std::is_base_of_v<Objektum, T>);
    T* t = new T(nev);
    Objektum* o = (Objektum*)t;
    check<std::string>(o->azon, nev,
        getType(t) +
        " Objektum azon hibas erteket ad vissza.");
    check<double>(o->TavSzorzo(), tavSz,
        getType(t) +
        " Objektum TavSzorzo() hibas erteket ad vissza.");
    check<double>(o->TomegSzorzo(), tomSz,
        getType(t) +
        " Objektum TomegSzorzo() hibas erteket ad vissza.");
    check<bool>(o->IsAszteroida(), aszt,
        getType(t) +
        " Objektum IsAszteroida() hibas erteket ad vissza.");
    delete o;
}

#endif
