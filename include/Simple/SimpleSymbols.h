#ifndef __SIMPLE_SYMBOLS_H__
#define __SIMPLE_SYMBOLS_H__

#include <string>

/**
 *  In this challenge a string like
 *  "b+c+asd==+d+" is given. All 
 *  letters should be surrounded by
 *  '+' 's. If not, return false string
 * 
 */

inline bool isLetter(char c)
{
    if((c >= 65 && c <=90) || (c >= 97 && c <= 122))
        return true;

    return false;
}

inline std::string SimpleSymbols(std::string str)
{

    if(str.size() == 1 || str.size() == 0)
        return "false";

    for(size_t i=0; i<str.size(); i++)
    {
        if(isLetter(str[i]))
            if(i == 0 || str[i-1] != '+' || str[i+1] != '+')
                return "false";
    }

    return "true";
}


#endif