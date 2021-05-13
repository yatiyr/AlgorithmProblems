#ifndef __ARE_BRACKETS_BALANCED_H__
#define __ARE_BRACKETS_BALANCED_H__

#include <string>
#include <stack>

inline std::string AreBracketsBalanced(std::string str)
{
    std::stack<char> charStack;

    for(size_t i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
            charStack.push('(');
        else if(str[i] == ')')
        {
            if(charStack.empty())
                return std::to_string(0);

            charStack.pop();
        }
    }

    if(charStack.empty())
        return std::to_string(1);
    else
        return std::to_string(0);
        
}

#endif