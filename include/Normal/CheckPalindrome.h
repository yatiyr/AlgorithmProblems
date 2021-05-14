#ifndef __CHECK_PALINDROME_H__
#define __CHECK_PALINDROME_H__

#include <iostream>
#include <string>
#include <cmath>

/**
 *  We check whether a string is palindrome
 *  string does not change reading from backwards or 
 *  normal.
 *  
 *  FOr example racecar is a palindrome
 * 
 *  This implementation ignores non letter chars!
 */

bool isLetter(char c)
{
    if((c >= 65 && c <=90) || (c >= 97 && c <=122))
        return true;

    return false;
}

bool letterEqual(char c1, char c2)
{
    if((c1 == c2) || std::abs(c1 - c2) == 32)
        return true;

    return false;
}

std::string CheckPalindrome(std::string str)
{

    int reverseIndex = str.size() - 1;
    int normalIndex = 0;

    if(str.size() == 2)
        return "false";

    while(reverseIndex - normalIndex > 1)
    {
        while(!isLetter(str[normalIndex]))
            normalIndex++;
        while(!isLetter(str[reverseIndex]))
            reverseIndex--;

        if(!letterEqual(str[normalIndex], str[reverseIndex]))
            return "false";

        normalIndex++;
        reverseIndex--;
    }

    return "true";
}



#endif