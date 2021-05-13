#ifndef __SIMPLE_FACTORIAL_H__
#define __SIMPLE_FACTORIAL_H__


// So simple
inline int SimpleFactorial(int number)
{

    if(number == 1 || number == 0)
        return 1;

    return number * SimpleFactorial(number - 1);
}

#endif