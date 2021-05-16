#ifndef __SIMPLE_MODE_H__
#define __SIMPLE_MODE_H__

#include <string>
#include <unordered_map>

std::string SimpleMode(int arr[], int arrLength)
{
    std::unordered_map<int, int> hashMap;
    int mod = -1;
    int maxFreq = -1;

    for(int i=arrLength-1; i>=0; i--)
    {
        if(hashMap[arr[i]] != 0 && hashMap[arr[i]] >= maxFreq)
        {
            maxFreq = hashMap[arr[i]];
            mod = arr[i];
        }
        hashMap[arr[i]]++;
    }

    return std::to_string(mod);
}



#endif