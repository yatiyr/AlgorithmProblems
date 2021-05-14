#ifndef __RUN_LENGTH_H__
#define __RUN_LENGTH_H__

#include <string>

inline std::string RunLength(std::string str)
{
    std::string compressed = "";

    for(size_t i=0; i<str.size(); i++)
    {
        int count = 1;
        char c = str[i];

        if(str.size() > 1)
            while(c == str[i+1])
            {
                count++;
                i++;
            }

        compressed += std::to_string(count) + c;
    }

    return compressed;
}

#endif