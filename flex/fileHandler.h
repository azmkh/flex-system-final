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
#include <fstream>
#include <sstream>
#include "student.h"
#include "course.h"
#include "mark.h"
#include "attendance.h"
using namespace std;

class fileHandler
{
private:
    string filename;
    string mode;
    string data;

public:
    fileHandler(string filename, string mode, string data) : filename(filename), mode(mode), data(data){};
    void writeToStudents()
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            fout << data;
            cout << "Data successfully written to file: " << filename << endl;
            fout.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
    }
    void writeToCourses()
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            fout << data;
            cout << "Data successfully written to file: " << filename << endl;
            fout.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
    }
    void writeToMarks()
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            fout << data;
            cout << "Data successfully written to file: " << filename << endl;
            fout.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
    }
    void writeToAttendance()
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            fout << data;
            cout << "Data successfully written to file: " << filename << endl;
            fout.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
    }
    vector<student> readFromStudents()
    {
        vector<student> students;
        ifstream fin(filename);
        if (fin.is_open())
        {
            string line;
            while (getline(fin, line))
            {
                istringstream iss(line);
                string name;
                string rollNumber;
                string age;
                string contact;
                if (getline(iss, name, ',') &&
                    getline(iss, rollNumber, ',') &&
                    getline(iss, age, ',') &&
                    getline(iss, contact))
                {
                    student new_student(name, rollNumber, age, contact);
                    students.push_back(new_student);
                }
                else
                {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            cout << "Data successfully read from file: " << filename << endl;
            fin.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
        return students;
    }
    vector<course> readFromCourses()
    {
        vector<course> courses;
        ifstream fin(filename);
        if (fin.is_open())
        {
            string line;
            while (getline(fin, line))
            {
                istringstream iss(line);
                string code;
                string name;
                string instructor;
                string credits;
                string capacity;
                string rollNumbers;
                if (getline(iss, code, ',') &&
                    getline(iss, name, ',') &&
                    getline(iss, instructor, ',') &&
                    getline(iss, credits, ',') &&
                    getline(iss, capacity, ','))
                {
                    course new_course(code, name, instructor, credits, capacity);
                    if (getline(iss, rollNumbers))
                    {
                        istringstream iss2(rollNumbers);
                        string rollNumber;
                        while (getline(iss2, rollNumber, ','))
                        {
                            new_course.add_student(rollNumber);
                        }
                    }
                    courses.push_back(new_course);
                }
                else
                {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            cout << "Data successfully read from file: " << filename << endl;
            fin.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
        return courses;
    }
    vector<mark> readFromMarks()
    {
        vector<mark> marks;
        ifstream fin(filename);
        if (fin.is_open())
        {
            string line;
            while (getline(fin, line))
            {
                istringstream iss(line);
                string cid;
                string rollNumber;
                string current_marks;
                if (getline(iss, cid, ',') &&
                    getline(iss, rollNumber, ',') &&
                    getline(iss, current_marks, ','))
                {
                    mark new_mark(cid, rollNumber, current_marks);
                    marks.push_back(new_mark);
                }
                else
                {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            cout << "Data successfully read from file: " << filename << endl;
            fin.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
        return marks;
    }
    vector<attendance> readFromAttendance()
    {
        vector<attendance> attendances;
        ifstream fin(filename);
        if (fin.is_open())
        {
            string line;
            while (getline(fin, line))
            {
                istringstream iss(line);
                string date;
                string cid;
                string rollNumber;
                string c;
                bool present;
                if (getline(iss, date, ',') &&
                    getline(iss, cid, ',') &&
                    getline(iss, rollNumber, ',') &&
                    getline(iss, c, ','))
                {
                    if (c == "1")
                        present = 1;
                    else
                        present = 0;
                    attendance new_attendance(date, cid, rollNumber, present);
                    attendances.push_back(new_attendance);
                }
                else
                {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            cout << "Data successfully read from file: " << filename << endl;
            fin.close();
        }
        else
        {
            cout << "Error opening file!\n";
        }
        return attendances;
    }
};