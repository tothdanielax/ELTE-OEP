#pragma once

#include <vector>

using namespace std;

class FileSystem {
    protected:
        vector<Entry*> entry;
        
    public:
        FileSystem(const vector<Entry*> &entry2) {
            entry = entry2;
        }

        ~FileSystem() {
            for(Entry* entry2 : entry) {
                delete entry2;
            }
        }
        
        vector<Entry*> GetEntries() const {
                return entry;
        }

        
};