#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <list>
#include <cstring>
using namespace std;
class attendance
{
private:
    string date;
    string cid;
    string rollNumber;
    bool present;

public:
    attendance(string date, string cid, string rollNumber, bool present) : date(date), cid(cid), rollNumber(rollNumber), present(present){};
    map<string, std::vector<attendance> > groupAttendancesByCID(vector<attendance> &allAttendances)
    {
        map<string, vector<attendance> > groupedAttendances;

        for (const auto &attendance_i : allAttendances)
        {
            groupedAttendances[attendance_i.cid].push_back(attendance_i);
        }

        return groupedAttendances;
    }

    friend class validator;
    friend class system;
};