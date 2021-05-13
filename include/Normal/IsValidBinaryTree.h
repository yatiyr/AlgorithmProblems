#ifndef __IS_VALID_BINARY_TREE_H__
#define __IS_VALID_BINARY_TREE_H__

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

struct Pair
{
    int first;
    int second;
};

/**
 *  In this problem, an array of strings is
 *  given and we determine whether we can build
 *  a valid binary tree with them or not.
 * 
 *  Input is like this;
 * 
 *  {"(1,2)", "(2,4)", "(7,2)"}
 * 
 *  first element of pairs is child
 *  second element is the parent
 * 
 */

inline std::vector<Pair> extractPairs(std::string strArr[], int arrLength)
{
    std::vector<Pair> result;
    std::string line;

    for(int i=0; i<arrLength; i++)
    {
        Pair p;
        std::stringstream ss(strArr[i].substr(1, strArr[i].size() - 1));

        std::getline(ss, line, ',');
        p.first = atoi(line.c_str());
        std::getline(ss, line, ',');
        p.second = atoi(line.c_str());
        result.push_back(p);
    }

    return result;
}

inline std::string isTreePossible(std::vector<Pair> pairVec)
{
    std::unordered_map<int, int> parentMap;
    std::unordered_map<int, int> childrenMap;

    for(size_t i=0; i<pairVec.size(); i++)
    {
        parentMap[pairVec[i].first] += 1;
        childrenMap[pairVec[i].second] += 1;

        if(parentMap[pairVec[i].first] > 1 || childrenMap[pairVec[i].second] > 2)
            return "false";
    }

    return "true";
}

inline std::string IsValidBinaryTree(std::string strArr[], int arrLength)
{
    std::vector<Pair> pairVec = extractPairs(strArr, arrLength);
    return isTreePossible(pairVec);
}



#endif