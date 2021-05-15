#ifndef __CAESAR_CIPHER_H__
#define __CAESAR_CIPHER_H__

#include <string>

/**
 * Caesar cipher shifts letters in the words in the alpabet
 * for num times. 
 * 
 */

inline bool isLetter(char c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;

    return false;
}

std::string CaesarCipher(std::string str, int num)
{

    for(size_t i=0; i<str.size(); i++)
    {
        if(isLetter(str[i]))
        {
            str[i] += (num%25);
            if(!isLetter(str[i]))
                str[i] -= 26;
        }
    }

    return str;
}


#endif