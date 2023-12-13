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
class course
{
private:
    string code;
    string name;
    string instructor;
    string credits;
    string capacity;
    vector<string> student_rollNumbers;

public:
    course(string code, string name, string instructor, string credits, string capacity)
    {
        this->code = code;
        this->name = name;
        this->instructor = instructor;
        this->credits = credits;
        this->capacity = capacity;
    }
    void display_students_in_course()
    {
        cout << "Students enrolled in course, " << name << ", are: \n";
        for (int i = 0; i < student_rollNumbers.size(); i++)
        {
            cout << student_rollNumbers[i] << endl;
        }
    }
    void display_course()
    {
        cout << "Code: " << code << "\t";
        cout << "Name: " << name << endl;
        cout << "Instructor: " << instructor << "\t";
        cout << "Credits: " << credits << endl;
        cout << "Capacity: " << capacity << endl;
        this->display_students_in_course();
    }
    void add_student(string rollNo)
    {
        student_rollNumbers.push_back(rollNo);
    }
    void remove_student(string rollNo)
    {
        student_rollNumbers.erase(remove(student_rollNumbers.begin(), student_rollNumbers.end(), rollNo), student_rollNumbers.end());
    }
    friend class validator;
    friend class system;
};