#ifndef __CAPITILIZE_WORD_BEGINNINGS_H__
#define __CAPITILIZE_WORD_BEGINNINGS_H__

#include <string>


inline int isLetter(char c)
{
    if(c >= 65 && c <= 90)
        return 2;
    else if(c >= 97 && c<= 122)
        return 1;

    return 0;
}

inline std::string CapitilizeWordBeginnings(std::string str)
{
    bool wordBeginning = true;

    std::string newStr = "";

    for(size_t i=0; i<str.size(); i++)
    {

        char manipulated = str[i];

        if(manipulated == ' ')
            wordBeginning = true;
        else if(wordBeginning)
        {
            if(isLetter(manipulated) == 1)
                manipulated -= 32;

            wordBeginning = false;
        }

        newStr += manipulated;

    }

    return newStr;
}




#endif