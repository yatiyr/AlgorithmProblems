#ifndef __CONSECUTIVE_H__
#define __CONSECUTIVE_H__

#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

/**
 * Have the function Consecutive(arr) take the array of integers stored in arr and return the minimum number of integers needed to make
 * the contents of arr consecutive from the lowest number to the highest number. For example: If arr contains [4, 8, 6] then the output
 * should be 2 because two numbers need to be added to the array (5 and 7) to make it a consecutive array of numbers from 4 to 8. Negative
 * numbers may be entered as parameters and no array will have less than 2 elements.
 * 
 */

std::string Consecutive(int arr[], int arrLength)
{

    std::unordered_map<int, int> hashMap;

    int maxVal = 0;
    int minVal = INT_MAX;

    for(int i=0; i<arrLength; i++)
    {
        hashMap[arr[i]]++;

        if(arr[i] > maxVal)
            maxVal = arr[i];
        if(arr[i] < minVal)
            minVal = arr[i];
    }

    int count = 0;

    for(int i=minVal+1; i<maxVal; i++)
        if(hashMap.find(i) == hashMap.end())
            count++;

    return std::to_string(count);
}



#endif