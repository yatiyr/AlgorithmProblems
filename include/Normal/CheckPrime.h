#ifndef __CHECK_PRIME_H__
#define __CHECK_PRIME_H__

#include <string>

/**
 *  Checks value is prime or not
 *  value is between 1 and 2^16
 */

inline std::string CheckPrime(int num)
{

    if(num == 1)
        return "false";

    for(int i=2; i<=num/2; i++)
        if(num % i == 0)
            return "false";

    return "true";
}


#endif