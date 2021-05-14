#ifndef __ARITHMETIC_GEOMETRIC_SEQUENCE_H__
#define __ARITHMETIC_GEOMETRIC_SEQUENCE_H__

#include <string>

std::string ArithmeticGeometricSequence(int arr[], int arrLength)
{

    if(arrLength == 0 || arrLength == 1)
        return "-1";

    int difference = arr[1] - arr[0];
    int ratio      = arr[1] / arr[0];

    bool arithmeticPath = false;
    bool geometricPath  = false;

    for(int i=2; i<arrLength; i++)
    {
        int newDifference = arr[i] - arr[i-1];
        int newRatio      = arr[i] / arr[i-1];

        if(newDifference == difference)
            arithmeticPath = true;
        if(ratio == newRatio)
            geometricPath = true;

        if(arithmeticPath)
            if(difference != newDifference)
                return "-1";
        
        if(geometricPath)
            if(ratio != newRatio)
                return "-1";

        difference = newDifference;
        ratio      = newRatio;
    }

    if(arithmeticPath)
        return "Arithmetic";
    else if(geometricPath)
        return "Geometric";

    return "-1";
}


#endif