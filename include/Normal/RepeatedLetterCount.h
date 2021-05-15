#ifndef __REPEATED_LETTER_COUNT_H__
#define __REPEATED_LETTER_COUNT_H__

#include <string>
#include <sstream>


/**
 * Returns the word with greatest repeated letter count
 * If there is no such word return -1 string
 */

inline bool isLetter(char c)
{
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;

    return false;
}


inline std::string RepeatedLetterCount(std::string str)
{

    std::stringstream ss(str);
    std::string resultWord = "";
    std::string word;
    int maximumRepeatCount = 0;

    while(std::getline(ss, word, ' '))
    {
        int wordHashTable[128] = {0};
        int repeatedCount = 0;

        for(size_t i=0; i<word.size(); i++)
        {
            if(isLetter(word[i]))
            {
                if(wordHashTable[word[i]] > 0)
                    repeatedCount++;
                wordHashTable[word[i]]++;
            }
        }

        if(repeatedCount > maximumRepeatCount)
        {
            resultWord = word;
            maximumRepeatCount = repeatedCount;
        }
    }

    if(resultWord == "")
        return "-1";

    return resultWord;
}


#endif