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
class mark
{
private:
    string cid;
    string rollNumber;
    string marks;

public:
    mark(string cid, string rollNumber, string marks) : cid(cid), rollNumber(rollNumber), marks(marks) {}
    map<string, vector<mark> > groupMarksByCID(vector<mark> &marks)
    {
        map<string, vector<mark> > groupedMarks;
        for (const auto &mark_i : marks)
        {
            groupedMarks[mark_i.cid].push_back(mark_i);
        }
        return groupedMarks;
    }
    friend class validator;
    friend class system;
};