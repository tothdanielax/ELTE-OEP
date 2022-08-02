#pragma once

class Entry {
public:
    // ld. File.hpp (másképp nem jó)
    virtual int GetSize() const = 0;

    //-Wall -Wextra miért jelez warningot, ha nem teszem virtuallá a destruktort az Entry-ben?
    virtual ~Entry() {}
};