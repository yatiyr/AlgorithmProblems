#ifndef __OPTIMAL_ASSIGNMENTS_H__
#define __OPTIMAL_ASSIGNMENTS_H__

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

/**
 * ---------------------------------- QUESTION -----------------------------------------
 * Have the function OptimalAssignments(strArr) read strArr which will 
 * represent an NxN matrix and it will be in the following format: ["(n,n,n...)","(...)",...] 
 * where the n's represent integers. This matrix represents a machine at row i performing task at column j.
 * The cost for this is matrix[i][j]. Your program should determine what machine should perform what task so
 * as to minimize the whole cost and it should return the pairings of machines to tasks in the following
 * format: (i-j)(...)... Only one machine can perform one task. 
 * For example: if strArr is ["(5,4,2)","(12,4,3)","(3,4,13)"] then your program 
 * should return (1-3)(2-2)(3-1) because assigning the machines to these tasks gives the least cost. 
 * The matrix will range from 2x2 to 6x6, there will be no negative costs in the matrix, and there will 
 * always be a unique answer.
 */


inline std::vector<std::vector<int>> extractMatrix(std::string strArr[], int arrLength)
{
    std::vector<std::vector<int>> extractMatrix;
    for(int i=0; i<arrLength; i++)
    {
        std::vector<int> row;
        std::string rowStr = strArr[i];
        rowStr.erase(0, 1);
        rowStr.erase(rowStr.size() - 1, 1);

        std::stringstream ss(rowStr);
        std::string line = "";

        while(std::getline(ss, line, ','))
        {
            int value = 0;
            std::stringstream numSS(line);
            numSS >> value;
            row.push_back(value);
        }

        extractMatrix.push_back(row);
    }

    return extractMatrix;
}

inline int getTotalCost(std::vector<std::vector<int>>& extractMatrix, std::vector<int>& permutation)
{
    int size = permutation.size();
    int sum  = 0;

    for(int i=0; i<size; i++)
        sum+= extractMatrix[i][permutation[i]];

    return sum;
}

inline std::string OptimalAssignments(std::string strArr[], int arrLength)
{
    std::string resultStr = "";

    std::vector<std::vector<int>> extractedMatrix = extractMatrix(strArr, arrLength);
    std::vector<int> tasks;

    for(int i=0; i<arrLength; i++)
        tasks.push_back(i);

    std::vector<int> bestTaskPermutation = tasks;
    int bestCost = getTotalCost(extractedMatrix, tasks);

    while(std::next_permutation(tasks.begin(), tasks.end()))
    {
        int cost = getTotalCost(extractedMatrix, tasks);
        if(cost < bestCost)
        {
            bestCost = cost;
            bestTaskPermutation = tasks;
        }
    }

    for(int i=0; i<arrLength; i++)
        resultStr += "(" + std::to_string(i+1) + "-" + std::to_string(bestTaskPermutation[i] + 1) + ")";

    return resultStr;
}



#endif