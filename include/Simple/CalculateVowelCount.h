#ifndef __CALCULATE_VOWEL_COUNT_H__
#define __CALCULATE_VOWEL_COUNT_H__

#include <string>

inline bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
       c == 'A'  || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;

    return false;
}

inline std::string CalculateVowelCount(std::string str)
{

    int count = 0;
    for(size_t i=0; i<str.size(); i++)
    {
        if(isVowel(str[i]))
            count++;
    }

    return std::to_string(count);

}


#endif