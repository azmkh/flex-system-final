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
class student
{
private: //attributes
    string name;
    string rollNo;
    string age;
    string contact;

public:
    student(string name, string rollNo, string age, string contact) : name(name), age(age), contact(contact), rollNo(rollNo){}; //constructor
    //parametrized constructor

    void enroll(vector<student> &students) //adds obj to vector of students
    {
        students.push_back(*this);
    }

    bool compare_rollNumber(string rollNumber) //simple comparision
        //this refers to same instance of class
    {
        if (this->rollNo == rollNumber)
            return 1;
        return 0;
    }
    void update(string name, string age, string contact)
    {//empty check for avaliability to fill
        if (!name.empty())
            this->name = name;

        if (!age.empty())
            this->age = age;

        if (!contact.empty())
            this->contact = contact;
    }
    void register_course(string courseId)
    {
        ;
    }
    void drop_course(string courseId)
    {
        ;
    }
    void display()
    {
        cout << "Name: " << name << "\t";
        cout << "RollNumber: " << rollNo << endl;
        cout << "Age: " << age << "\t";
        cout << "Contact: " << contact << endl;
    }
    friend class validator; //accesses privates of student class
    friend class system; //same
};