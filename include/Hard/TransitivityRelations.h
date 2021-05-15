#ifndef __TRANSITIVITY_RELATIONS_H__
#define __TRANSITIVITY_RELATIONS_H__

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct Pair
{
    int node1;
    int node2;
};

bool comparePairs(const Pair& p1, const Pair& p2)
{
    if(p1.node1 == p2.node1)
        return p1.node2 < p2.node2;
    
    return p1.node1 < p2.node1;
}

std::vector<std::vector<int>> extractMatrix(std::string strArr[], int arrLength)
{
    std::vector<std::vector<int>> extractedMatrix;

    for(int i=0; i<arrLength; i++)
    {
        std::vector<int> row;
        std::string rowString = strArr[i];
        rowString.erase(0,1);
        rowString.erase(rowString.size() - 1, 1);

        std::stringstream rowSS(rowString);
        std::string line = "";

        while(std::getline(rowSS, line, ','))
        {
            int value = 0;
            std::stringstream valueSS(line);
            valueSS >> value;
            row.push_back(value);
        }

        extractedMatrix.push_back(row);
    }

    return extractedMatrix;
}

std::vector<Pair> getConnections(std::vector<std::vector<int>>& matrix)
{
    std::vector<Pair> connections;
    int size = matrix.size();
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(matrix[i][j] == 1)
            {
                Pair p;
                p.node1 = i;
                p.node2 = j;
                connections.push_back(p);
            }
        }
    }

    return connections;
}

bool checkExistenceOfConnection(std::vector<Pair>& p, int node1, int node2)
{
    for(const auto& element : p)
        if(element.node1 == node1 && element.node2 == node2)
            return true;

    return false;
}

std::vector<int> checkExistenceOfSource(std::vector<Pair>& p, int node1)
{
    std::vector<int> destinationVector;

    for(const auto& element : p)
        if(element.node1 == node1)
            destinationVector.push_back(element.node2);

    return destinationVector;
}

std::vector<Pair> checkTransitive(std::vector<Pair>& connections)
{
    std::vector<Pair> neededConnections;

    int size = connections.size();
    for(int i=0; i<size; i++)
    {
        std::vector<int> destinations = checkExistenceOfSource(connections, connections[i].node2);
        int sizeDestinations = destinations.size();

        for(int j=0; j<sizeDestinations; j++)
            if(!checkExistenceOfConnection(connections, connections[i].node1, destinations[j]))
            {
                Pair p;
                p.node1 = connections[i].node1;
                p.node2 = destinations[j];
                if(!checkExistenceOfConnection(neededConnections, p.node1, p.node2) && p.node1 != p.node2)
                    neededConnections.push_back(p);
            }
    }

    return neededConnections;
}

std::string TransitivityRelations(std::string strArr[], int arrLength)
{
    std::vector<std::vector<int>> extractedMatrix = extractMatrix(strArr, arrLength);
    std::vector<Pair> connections = getConnections(extractedMatrix);
    std::vector<Pair> addedConnections = checkTransitive(connections);
    std::vector<Pair> neededConnections = addedConnections;

    for(size_t i=0; i<addedConnections.size(); i++)
        connections.push_back(addedConnections[i]);

    while(!addedConnections.empty())
    {
        addedConnections = checkTransitive(connections);
        for(size_t i=0; i<addedConnections.size(); i++)
        {
            neededConnections.push_back(addedConnections[i]);
            connections.push_back(addedConnections[i]);
        }
    }

    std::sort(neededConnections.begin(), neededConnections.end(), comparePairs);

    if(neededConnections.empty())
        return "transitive";
    else
    {
        std::string neededConnectionsString = "";
        for(size_t i=0; i<neededConnections.size()-1; i++)
            neededConnectionsString += "(" +
                                        std::to_string(neededConnections[i].node1) +
                                        "," +
                                        std::to_string(neededConnections[i].node2) +
                                        ")-";

        neededConnectionsString += "(" +
                                    std::to_string(neededConnections[neededConnections.size() - 1].node1) +
                                    "," +
                                    std::to_string(neededConnections[neededConnections.size() - 1].node2) +
                                    ")";
        return neededConnectionsString;
    }
}

#endif