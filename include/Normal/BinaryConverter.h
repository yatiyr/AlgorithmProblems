#ifndef __BINARY_CONVERTER_H__
#define __BINARY_CONVERTER_H__

#include <string>

inline std::string BinaryConverter(std::string str)
{

    int decimal = 0;
    for(int i=0; i<str.size(); i++)
    {
        int backwards = str.size() - 1 - i;
        if(str[backwards] == '1')
        {
            int val = (str[backwards] - 48) << i;
            decimal += val;
        }
    }
    return std::to_string(decimal);
}

#endif