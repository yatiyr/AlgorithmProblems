#include <iostream>

#include <Simple/CountingMinutesI.h>

#include <string>

using namespace std;

int main()
{
    string arr[9] = {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};

    string arr2[3] = {"(1,1,1)","(1,0,0)","(0,1,0)"};

    int arr3[4] = {1, 2, 2, 3};

    cout << CountingMinutesI("12:30pm-12:00am") << endl;


    return 0;
}