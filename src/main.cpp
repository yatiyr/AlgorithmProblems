#include <iostream>

#include <Normal/Consecutive.h>

#include <string>

using namespace std;

int main()
{
    string arr[9] = {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};

    string arr2[3] = {"(1,1,1)","(1,0,0)","(0,1,0)"};

    int arr3[13] = {1, 2, 2, 3 ,3 ,3 ,3, 1, 1, 1, 1, 1, 1};

    int arr4[3] = {1,2,4};

    cout << Consecutive(arr4, 3) << endl;


    return 0;
}