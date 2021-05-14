#ifndef __NTH_PRIME_H__
#define __NTH_PRIME_H__

#include <string>

inline bool isPrime(int num)
{
    if(num == 0 || num == 1)
        return false;

    for(int i=2; i<=num/2; i++)
        if(num % i == 0)
            return false;

    return true;
}

inline std::string NthPrime(int num)
{
    int count = 0;
    int numIterator = 0;

    while(count < num)
    {
        if(isPrime(numIterator))
            count++;
        numIterator++;
    }

    return std::to_string(numIterator - 1);
}


#endif