#ifndef __DIVISION_STRINGIFIED_H__
#define __DIVISION_STRINGIFIED_H__

#include <string>
#include <algorithm>

std::string stringifyDivision(int num1, int num2)
{
    float result = (float) num1 / num2;
    int rounded  = (int)(result + 0.5);
    int i=0;

    if(rounded >= 1000)
    {
        std::string resultString = "";
        int roundedTraverser = rounded;
        while(roundedTraverser > 0)
        {
            if(i % 4 == 3)
            {
                resultString += ",";
                i++;
                continue;
            }
            else
            {
                int digit = roundedTraverser % 10;
                roundedTraverser /= 10;
                resultString += std::to_string(digit);
                i++;
            }
        }
        std::reverse(resultString.begin(), resultString.end());
        return resultString;
    }

    return std::to_string(rounded);
}

std::string DivisionStringified(int num1, int num2)
{
    return stringifyDivision(num1, num2);
}


#endif