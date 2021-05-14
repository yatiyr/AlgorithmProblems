#ifndef __SORT_STRING_H__
#define __SORT_STRING_H__

#include <string>

inline std::string SortString(std::string str)
{
    for(size_t i=0; i<str.size(); i++)
        for(size_t j=i + 1; j<str.size(); j++)
        {
            if(str[i] > str[j])
            {
                char tmp = str[j];
                str[j] = str[i];
                str[i] = tmp;
            }
        }

    return str; 
}

#endif