#ifndef __FIND_LONGEST_WORD_H__
#define __FIND_LONGEST_WORD_H__

#include <string>

inline bool isLetter(char c)
{
    if((c >= 65 && c <=90) || (c >=97 && c <=122) || (c >= 48 && c <=57))
        return true;

    return false;
}

inline std::string  FindLongestWord(std::string str)
{

    std::string longestWord = "";
    std::string word        = "";

    int wordLength = 0;
    int count = 0;
    bool processingWord = false;

    for(size_t i=0; i<str.size(); i++)
    {
        if(isLetter(str[i]))
        {
            processingWord = true;
            word += str[i];
            count++;
        }
        else
        {
            processingWord = false;
        }

        if(i == str.size() - 1)
            processingWord = false;

        if(!processingWord)
        {
            if(count > wordLength)
            {
                wordLength = count;
                longestWord = word;
            }
            word.clear();
            count = 0;
        }
    }

    return longestWord;
}


#endif