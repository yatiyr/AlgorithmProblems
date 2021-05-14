#ifndef __GREATEST_COMMON_DIVISOR_H__
#define __GREATEST_COMMON_DIVISOR_H__

inline int GreatestCommonDivisor(int num1, int num2)
{
    int gcf = 1;

    if(num1 > num2)
    {
        for(int i=1; i<=num2; i++)
            if(num2 % i == 0 && num1 % i == 0)
                gcf = i;
    }
    else if(num1 < num2)
    {
        for(int i=1; i<=num1; i++)
            if(num2 % i == 0 && num1 % i == 0)
                gcf = i;
    }
    else
        gcf = num1;

    return gcf;
}


#endif