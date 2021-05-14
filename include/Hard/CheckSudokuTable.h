#ifndef __CHECK_SUDOKU_TABLE_H__
#define __CHECK_SUDOKU_TABLE_H__

#include <string>
#include <sstream>
#include <vector>


/**
 * In this problem, we check whether a sudoku table is valid or not
 * every row, column and 3x3 subgrid must have unique numbers in the
 * table. If we break these rules, we report in which subgrids errors
 * occured. Input will be a string array like;
 * 
 * {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"}
 * 
 * and output will be;
 * 
 * "1,3,4"
 * 
 */

struct Coordinate
{
    int i;
    int j;
};

inline int giveQuadrantFromIndexes(int i, int j)
{
    return j/3 +  3*(i/3);
}

inline int giveQuadrantElement(const std::vector<std::vector<int>>& table, int quadrantNo, int offset)
{
    int i = 3*(quadrantNo/3) + offset/3;
    int j = 3*(quadrantNo%3) + offset%3;

    return table[i][j];
}

inline Coordinate giveQuadrantCoordinates(int quadrantNo, int offset)
{
    Coordinate result;
    result.i = 3*(quadrantNo/3) + offset/3;
    result.j = 3*(quadrantNo%3) + offset%3;

    return result;
}

inline std::vector<std::vector<int>> extractTable(std::string strArr[], int arrLength)
{
    std::vector<std::vector<int>> table;

    for(int i=0; i<arrLength; i++)
    {
        std::vector<int> row;
        std::string rowStr = strArr[i];

        rowStr.erase(0,1);
        rowStr.erase(rowStr.size() - 1, 1);

        std::stringstream ss(rowStr);
        std::string line = "";
        while(getline(ss, line, ','))
        {
            int number = 0;
            std::stringstream nS(line);
            nS >> number;
            row.push_back(number);
        }
        table.push_back(row);
    }

    return table;
}

inline void checkErrors(const std::vector<std::vector<int>>& table, int quadrantErrorCounter[])
{
    std::vector<Coordinate> errorCoordinates;

    // check rows
    for(size_t i=0; i<table.size(); i++)
    {
        int rowElementCount[10] = {0};
        for(size_t j=0; j<table[i].size(); j++)
            rowElementCount[table[i][j]]++;

        for(size_t j=0; j<table[i].size(); j++)
            if(rowElementCount[table[i][j]] > 1 && table[i][j] != 0)
            {
                Coordinate errorCoordinate;
                errorCoordinate.i = i;
                errorCoordinate.j = j;
                errorCoordinates.push_back(errorCoordinate);
            }
    }

    // check columns
    for(size_t j=0; j<table[0].size(); j++)
    {
        int columnElementCount[10] = {0};
        for(size_t i=0; i<table.size(); i++)
            columnElementCount[table[i][j]]++;

        for(size_t i=0; i<table.size(); i++)
            if(columnElementCount[table[i][j]] > 1 && table[i][j] != 0)
            {
                Coordinate errorCoordinate;
                errorCoordinate.i = i;
                errorCoordinate.j = j;
                errorCoordinates.push_back(errorCoordinate);
            }
    }

    // check subgrids
    for(int i=0; i<9; i++)
    {
        int quadrantElementCount[10] = {0};
        for(int j=0; j<9; j++)
        {
            int element = giveQuadrantElement(table, i, j);
            quadrantElementCount[element]++;
        }

        for(int j=0; j<9; j++)
        {
            int element = giveQuadrantElement(table, i, j);
            if(quadrantElementCount[element] > 1 && element != 0)
            {
                Coordinate errorCoordinate = giveQuadrantCoordinates(i, j);
                errorCoordinates.push_back(errorCoordinate);
            }
        }
    }

    // fill in error counts of subgrids
    for(size_t i=0; i<errorCoordinates.size(); i++)
        quadrantErrorCounter[giveQuadrantFromIndexes(errorCoordinates[i].i, errorCoordinates[i].j)]++;

}


inline std::string CheckSudokuTable(std::string strArr[], int arrLength)
{
    std::string result = "";

    // there are 9 subgrids and we hold
    // a table to count errors on them
    int quadrantErrorCounter[9] = {0};

    // extract the table
    std::vector<std::vector<int>> table = extractTable(strArr, arrLength);

    checkErrors(table, quadrantErrorCounter);

    for(int i=0; i<9; i++)
    {
        if(quadrantErrorCounter[i] > 0)
            result += std::to_string(i + 1) + ",";
    }

    if(result.size() == 0)
        return "legal";

    result.erase(result.size() - 1, 1);

    return result;
}

#endif