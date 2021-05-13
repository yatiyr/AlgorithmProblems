#ifndef __COMBINATION_OF_BRACKETS_H__
#define __COMBINATION_OF_BRACKETS_H__

#include <string>

inline void CalculateCombinations(int left, int right, int& count)
{
    if(left == 0 && right == 0)
        count++;
    if(left > 0)
        CalculateCombinations(left - 1, right + 1, count);
    if(right > 0)
        CalculateCombinations(left, right - 1, count);
}

inline int CombinationOfBrackets(int number)
{
    int result = 0;
    CalculateCombinations(number, 0, result);
    return result;
}

#endif