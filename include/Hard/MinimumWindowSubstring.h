#ifndef __MINIMUM_WINDOW_SUBSTRING_H__
#define __MINIMIM_WINDOW_SUBSTRING_H__

#include <string>

inline std::string MinimumWindowSubstring(std::string strArr[], int arrLength)
{
    std::string N = strArr[0];
    std::string K = strArr[1];

    int sizeN = N.size();
    int sizeK = K.size();

    int hashK[256] = {0};
    int hashN[256] = {0};

    int leftPointer = 0;
    int minWindowLength = 100;
    int kCharCount = 0;
    int finalStrBeginning = 0;

    // fill hash table of K string
    for(int i=0; i<sizeK; i++)
    {
        hashK[K[i]]++;
    }

    int windowLength = -1;

    // increasing right pointer in a loop
    for(int rightPointer=0; rightPointer<sizeN; rightPointer++)
    {
        hashN[N[rightPointer]]++;

        // We increase kCharCount if string K has more elements
        // of that char from N string
        if(hashN[N[rightPointer]] <= hashK[N[rightPointer]])
            kCharCount++;

        // If we find a valid window
        if(kCharCount == sizeK)
        {
            windowLength = rightPointer - leftPointer + 1;

            // We minimize window by moving left pointer to right
            // as much as we can without losing validity
            while(hashN[N[leftPointer]] > hashK[N[leftPointer]] &&
                  windowLength > sizeK)
            {
                hashN[N[leftPointer]]--;
                leftPointer++;
            }

            // Recalculate window length and test whether
            // it is smaller than current window length
            // if so, update it
            windowLength = rightPointer - leftPointer + 1;
            if(windowLength < minWindowLength)
            {
                finalStrBeginning = leftPointer;
                minWindowLength = windowLength;
            }
        }
    }

    if(windowLength != -1)
        return N.substr(finalStrBeginning, minWindowLength);
    else
        return "no substring";
}


#endif