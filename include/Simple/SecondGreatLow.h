#ifndef __SECOND_GREAT_LOW_H__
#define __SECOND_GREAT_LOW_H__

#include <string>
#include <bits/stdc++.h>

std::string SecondGreatLow(int arr[], int arrLength)
{
    if(arrLength == 2)
    {
        if(arr[0] > arr[1])
            return std::to_string(arr[0]) + " " + std::to_string(arr[1]);
        return std::to_string(arr[1]) + " " + std::to_string(arr[0]);
    }

    int greatest = 0;
    int secondGreatest = 0;

    int lowest = INT_MAX;
    int secondLowest = 0;
    
    bool lowestFlag = false;
    bool highestFlag = false;

    for(int i=0; i<arrLength; i++)
    {
        if(arr[i] > greatest)
        {
            highestFlag = true;
            secondGreatest = greatest;
            greatest = arr[i];
        }
        else if(highestFlag && arr[i] > secondGreatest && arr[i] != greatest)
            secondGreatest = arr[i];

        if(arr[i] < lowest)
        {
            lowestFlag = true;
            secondLowest = lowest;
            lowest = arr[i];
        }
        else if(lowestFlag && arr[i] < secondLowest && arr[i] != lowest)
            secondLowest = arr[i];
    }

    return std::to_string(secondLowest) + " " + std::to_string(secondGreatest);
}


#endif