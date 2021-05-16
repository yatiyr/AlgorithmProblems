#ifndef __FORMATTED_DIVISION_H__
#define __FORMATTED_DIVISION_H__

#include <string>

std::string FormattedDivision(int num1, int num2)
{
    double divisionResult = ((double) num1) / ((double) num2);
    std::string result = std::to_string(divisionResult);
    size_t dotPos = result.find(".");

    if(result[dotPos + 5] >= '5')
    {
        double newVal = divisionResult + 0.0001;
        result = std::to_string(newVal);
    }

    for(int i=dotPos-3; i>0; i -=3)
        result.insert(i, ",");

    dotPos = result.find(".");
    return result.substr(0, dotPos + 5);
}

#endif