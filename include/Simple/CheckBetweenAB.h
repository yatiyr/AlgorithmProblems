#ifndef __CHECK_BETWEEN_AB_H__
#define __CHECK_BETWEEN_AB_H__


#include <string>


inline std::string CheckBetweenAB(std::string str)
{
    bool seenA;
    bool seenB;

    int charCount=0;
    for(size_t i=0; i<str.size(); i++)
    {
        if(str[i] == 'a' && seenB)
        {
            seenA = true;
            seenB = false;

            if(charCount == 3)
                return "true";

            charCount = 0;
        }
        else if(str[i] == 'b' && seenA)
        {
            seenB = true;
            seenA = false;

            if(charCount == 3)
                return "true";

            charCount = 0;
        }
        else if(str[i] == 'a')
        {
            seenA = true;
            charCount = 0;
        }
        else if(str[i] == 'b')
        {
            seenB = true;
            charCount = 0;
        }
        else
        {
            if(seenA || seenB)
                charCount++;
        }
    }

    return "false";
}



#endif