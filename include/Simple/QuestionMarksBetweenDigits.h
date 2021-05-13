#ifndef __QUESTION_MARKS_BETWEEN_DIGITS_H__
#define __QUESTION_MARKS_BETWEEN_DIGITS_H__


#include <string>

/**
 *  This function checks a string and tells us
 *  whether there are exactly three question marks
 *  between pairs of digits and digits' sum needs
 *  to be 10
 * 
 *  if there are no such pairs function returns false
 * 
 */

inline std::string QuestionMarksBetweenDigits(std::string str)
{
    bool digitsRead;

    int oldVal = 0;
    int newVal = 0;
    int qmCount = 0;

    bool oneExampleFound = false;

    for(size_t i=0; i<str.size(); i++)
    {
        if(std::isdigit(str[i]) && !digitsRead)
        {
            oldVal = str[i] - '0';
            newVal = oldVal;
            digitsRead = true;
        }
        else if(std::isdigit(str[i]) && digitsRead)
        {
            oldVal = newVal;
            newVal = str[i] - '0';
            int pairSum = oldVal + newVal;

            if(pairSum == 10 && qmCount != 3)
                return "false";

            else if(pairSum == 10 && qmCount == 3)
                oneExampleFound = true;

            qmCount = 0;
        }

        if(str[i] == '?' && digitsRead)
            qmCount++;
    }

    if(oneExampleFound)
        return "true";

    return "false";
}

#endif