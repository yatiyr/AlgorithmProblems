#include <iostream>

#include <Normal/GreatestCommonDivisor.h>

#include <string>

using namespace std;

int main()
{
    string arr[9] = {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};

    cout << GreatestCommonDivisor(12, 36) << endl;


    return 0;
}