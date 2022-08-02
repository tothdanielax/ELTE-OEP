#pragma once

#include "Entry.hpp"

class File : public Entry {
    private:
        int meret;

    public:
        File(int meret2) {
            meret = meret2;
        }

        ~File(){}

        virtual int GetSize() const override {
            return meret;
        }

        /* így nem működik, hiába returnolok Entry-ben 0-át/pure virtual functionnek csinálom meg (értem ezalatt azt, hogy = 0 [ez a pure virtual ugye?:)])
            ,azt kapom errornak, hogy ez nem override, de éppen hogy a return 0-át overrideolnám return meretnek

        int GetSize(int meret) const override
        {
            return meret;
        }

        */
};