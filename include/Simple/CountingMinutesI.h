#ifndef __COUNTING_MINUTES_I_H__
#define __COUNTING_MINUTES_I_H__

#include <string>
#include <sstream>

/**
 * Have the function CountingMinutesI(str) take the str parameter being passed which will be two times (each properly formatted with a colon and am or pm) 
 * separated by a hyphen and return the total number of minutes between the two times. The time will be in a 12 hour clock format. For example: if str is
 * 9:00am-10:00am then the output should be 60. If str is 1:00pm-11:00am the output should be 1320.
 * 
 */

std::string CountingMinutesI(std::string str)
{
    int res = 0;

    std::stringstream ss(str);
    std::string line = "";

    // d20 (distance to 0)
    int d20_1, d20_2;

    // ---------------- Reading first part ----------------- //
    std::getline(ss, line, ':');
    int hour1 = std::stoi(line);
    std::getline(ss, line, '-');
    int minute1 = std::stoi(std::string(line.begin(), line.begin() + 2));
    if(line[2] == 'p')
    {
        if(hour1 + 12 >= 24)
            hour1 -= 12;
        else
            hour1 += 12;
    }
    d20_1 = hour1*60 + minute1;

    // --------------- Reading second part ------------------ //
    std::getline(ss, line, ':');
    int hour2 = std::stoi(line);
    std::getline(ss, line, '\0');
    int minute2 = std::stoi(std::string(line.begin(), line.begin() + 2));
    if(line[2] == 'p')
    {
        if(hour2 + 12 >= 24)
            hour2 -= 12;
        else
            hour2 += 12;
    }
    d20_2 = hour2*60 + minute2;

    if(d20_1 > d20_2)
        res = 24*60 - (d20_1 - d20_2);
    else
        res = d20_2 - d20_1;

    return std::to_string(res);
}


#endif