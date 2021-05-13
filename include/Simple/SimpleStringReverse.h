#ifndef __SIMPLE_STRING_REVERSE_H__
#define __SIMPLE_STRING_REVERSE_H__

#include <string>

// So simple
inline std::string SimpleReverse(std::string str)
{

    if(str.size() == 1)
        return str;

    return SimpleReverse(str.substr(1, str.size())) +  str[0];
}


#endif