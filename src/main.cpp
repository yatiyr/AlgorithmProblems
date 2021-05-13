#include <iostream>

#include <Hard/MinimumWindowSubstring.h>

#include <string>

using namespace std;

int main()
{
    string arr[2] = {"aaabaaddae", "aed"};

    cout << MinimumWindowSubstring(arr, 2) << endl;


    return 0;
}