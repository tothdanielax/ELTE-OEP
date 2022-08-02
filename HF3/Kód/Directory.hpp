#pragma once

#include "Entry.hpp"
#include <vector>

using namespace std;

class Directory : public Entry
{
    /* így nem jó (és köszönöm a visszajelzéseket)
    private:
        int size;
    */

protected:
    vector<Entry *> entry;

public:
    Directory(const vector<Entry *> &entry2)
    {
        entry = entry2;
    }

    ~Directory()
    {
        for (Entry *entry2 : entry)
        {
            delete entry2;
        }
    }

    int GetSize() const override
    {
        int size = 0;
        for (Entry *entry2 : entry)
        {
            size += entry2->GetSize();
        }
        return size;
    }
};