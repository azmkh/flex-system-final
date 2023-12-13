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

class validator
{
private:
    string type;

public:
    validator(string name)
    {
        type = name;
    }
    bool course_validator(vector<course> courses, course new_course)
    {
        if (type == "course")
        {
            for (int i = 0; i < courses.size(); i++)
            {
                if (new_course.code == courses[i].code)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    bool course_validator(vector<course> courses, string cid)
    {
        if (type == "course")
        {
            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i].code == cid)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    bool student_validator(vector<student> students, student new_student)
    {
        if (type == "student")
        {
            for (int i = 0; i < students.size(); i++)
            {
                if (new_student.rollNo == students[i].rollNo)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    bool student_validator(vector<student> students, string rollNumber)
    {
        if (type == "student")
        {
            for (int i = 0; i < students.size(); i++)
            {
                if (rollNumber == students[i].rollNo)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    bool mark_validator(vector<mark> marks, mark new_mark)
    {
        for (int i = 0; i < marks.size(); i++)
        {
            if (marks[i].cid == new_mark.cid && marks[i].rollNumber == new_mark.rollNumber)
                return 0;
        }
        return 1;
    }
    bool attendance_validator(vector<attendance> attendances, attendance new_attendance)
    {
        for (int i = 0; i < attendances.size(); i++)
        {
            if (attendances[i].date == new_attendance.date && attendances[i].cid == new_attendance.cid && attendances[i].rollNumber == new_attendance.rollNumber)
            {
                return 0;
            }
        }
        return 1;
    }
};