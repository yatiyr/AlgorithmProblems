#include <iostream>

#include <Simple/FindIntersection.h>

#include <string>

using namespace std;

int main()
{
    string arr[2] = {"1, 2, 3,4, 5", "3, 4, 1, 1, 1"};

    cout << FindIntersection(arr) << endl;


    return 0;
}