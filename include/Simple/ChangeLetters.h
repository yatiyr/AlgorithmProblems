#ifndef __CHANGE_LETTERS_H__
#define __CHANGE_LETTERS_H__

#include <string>

inline int isLetter(char c)
{
    if(c >= 65 && c <= 90)
        return 2;
    else if(c >= 97 && c <= 122)
        return 1;
    
    return 0;
}

inline bool isVovel(char c)
{
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
       c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    
    return false;
}

inline std::string ChangeLetters(std::string str)
{
    std::string newStr = "";

    for(size_t i=0; i<str.size(); i++)
    {
        int iL = isLetter(str[i]);
        char manipulated = str[i];

        if(iL > 0)
        {
            manipulated = str[i] + 1;

            if(isVovel(manipulated) && iL != 2)
                manipulated -= 32;
        }

        newStr += manipulated;
    }

    return newStr;
}

#endif