#ifndef __STRING_SCRAMBLE_H__
#define __STRING_SCRAMBLE_H__

#include <string>

/**
 * We try to determine whether we can construct str2 from some elements
 * of str1
 * 
 * Example "asdasderen" , "eren" returns true
 */

inline std::string StringScramble(std::string str1, std::string str2)
{
    int str1Hash[256] = {0};
    int str2Hash[256] = {0};

    // fill in str1 hash
    for(size_t i=0; i<str1.size(); i++)
        str1Hash[str1[i]]++;

    // fill in str2 hash
    for(size_t i=0; i<str2.size(); i++)
        str2Hash[str2[i]]++;

    // check validity
    for(size_t i=0; i<str2.size(); i++)
        if(str1Hash[str2[i]] < str2Hash[str2[i]])
            return "false";

    return "true";
}

#endif