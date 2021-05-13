#ifndef __FIND_INTERSECTION_H__
#define __FIND_INTERSECTION_H__

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>


/**
 * ------------ EXPLANATION --------------
 * We give an array of strings which holds two
 * strings like;
 *  "1, 2, 3, 4" and "2, 5, 9, 19"
 * 
 * We read both of these strings and print
 * common elements. Lists have unique numbers
 */

inline std::vector<int> extractNumbers(std::string str)
{
    std::vector<int> result;
    std::stringstream ss(str);

    int value;
    std::string line;


    while(getline(ss, line, ','))
    {
        std::stringstream ssLine(line);
        ssLine >> value;
        result.push_back(value);
    }

    return result;
}

inline std::string vectorToString(std::vector<int> vec)
{
    std::string result = "";

    for(size_t i=0; i<vec.size() - 1; i++)
        result += std::to_string(vec[i]) + ",";

    if(vec.size() > 0)
        result += std::to_string(vec[vec.size() - 1]);

    return result;
}

inline std::string FindIntersection(std::string strings[])
{
    std::unordered_map<int, int> map;

    std::vector<int> list1 = extractNumbers(strings[0]);
    std::vector<int> list2 = extractNumbers(strings[1]);

    std::vector<int> resultNumbers;

    for(size_t i=0; i<list1.size(); i++)
    {
        map[list1[i]] = 1;
    }

    for(size_t i=0; i<list2.size(); i++)
    {
        if(map[list2[i]] == 1)
            resultNumbers.push_back(list2[i]);
    }
    
    if(resultNumbers.size() == 0)
        return "false";

    return vectorToString(resultNumbers);

}

#endif