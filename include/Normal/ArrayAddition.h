#ifndef __ARRAY_ADDITION_H__
#define __ARRAY_ADDITION_H__

#include <string>
#include <algorithm>

inline bool combinationSearch(int arr[],
                       int startIndex,
                       int stopIndex,
                       int currentTotal,
                       int targetTotal)
{

    // if we have reached target value
    // which is the highest val in the array
    if(currentTotal == targetTotal)
        return true;

    // we have reached to the end and could not
    // find target value, so this combination fails
    if(startIndex == stopIndex)
        return false;

    // We have two options, using current value
    // in startIndex or not using it
    return combinationSearch(arr,
                             startIndex + 1,
                             stopIndex,
                             currentTotal,
                             targetTotal) ||
            combinationSearch(arr,
                              startIndex + 1,
                              stopIndex,
                              currentTotal + arr[startIndex],
                              targetTotal);
}                       

inline std::string ArrayAddition(int arr[], int arrLength)
{
    std::sort(arr, arr + arrLength);

    if(arrLength == 2)
        return "false";

    if(combinationSearch(arr, 0, arrLength-1, 0, arr[arrLength-1]))
        return "true";

    return "false";
}

#endif