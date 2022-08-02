#include <iostream>

#include "Directory.hpp"
#include "Entry.hpp"
#include "File.hpp"
#include "FileSystem.hpp"

int main()
{
    const FileSystem fs({
        new Directory({}),
        new File(2048),
        new Directory({
            new Directory({
                new Directory({
                    new File(356),
                    new File(9632)
                }),
                new File(1755)
            }),
            new Directory({
                new File(177)
            }),
        }),  
        new File(6782)
    });

    for (const Entry *entry : fs.GetEntries())
    {
        std::cout << entry->GetSize() << std::endl;
    }
}