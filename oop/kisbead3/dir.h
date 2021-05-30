#include "entry.h"
#includ <vector>
#pragma once

class Directory : public Entry
{
    private:
        std::vector<Entry*> _entries;

    public:
        int getSize() override
        {
            int sum=0;
            for (entry: _entries)
            {
                sum+=entry->getSize();
            }
            return sum;
        }
};
