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

#include "student.h"
#include "course.h"
#include "mark.h"
#include "attendance.h"
#include "validator.h"
#include "fileHandler.h"
using namespace std;
//main system class controls menu

class system
{
private:
public:
    void main_menu()
    {
        vector<student> students; //vector classes
        vector<course> courses;
        vector<mark> marks;
        vector<attendance> attendances;

        fileHandler student_reader("students.txt", "read", ""); //new classes for student and courses text files
        fileHandler course_reader("courses.txt", "read", "");

        cout << "Welcome to Student Management System!\n";
        int choice;
        
        //first choice for student implementation
        //1 for continue 0 for exit

        while (1)
        {
            students = student_reader.readFromStudents(); //files loaded with data
            courses = course_reader.readFromCourses();

            cout << "Main Menu\n";
            cout << "1. Student\n";
            cout << "2. Course\n";
            cout << "3. Attendance\n";
            cout << "4. Marks\n";
            cout << "0. Exit\n";
            
            cin >> choice;   //calling app sub menus on each option
            if (choice == 1)
            {
                this->student_menu(students);
            }
            else if (choice == 2)
            {
                this->course_menu(students, courses);
            }
            else if (choice == 3)
            {
                this->attendance_menu(students, courses, attendances);
            }
            else if (choice == 4)
            {
                this->mark_menu(students, courses, marks);
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }
        cout << "Good Bye!\n";
    }

    void attendance_menu(vector<student> &students, vector<course> &courses, vector<attendance> &attendances)
    {
        fileHandler student_reader("students.txt", "read", ""); //making more classes for reader
        fileHandler course_reader("courses.txt", "read", "");
        fileHandler attendance_reader("attendance.txt", "read", "");
        int choice;
        while (1)
        {
            students = student_reader.readFromStudents();   //initializing data from files
            courses = course_reader.readFromCourses();
            attendances = attendance_reader.readFromAttendance();
            cout << "1. Display Attendance\n";
            cout << "2. Mark Attendance\n";
            cout << "0. Back\n";
            cin >> choice;
            cin.ignore();
            if (choice == 0)
                break;
            else if (choice == 1)
            {
                attendance *ptr = nullptr;         //attendance class ka ptr passing
                map<string, vector<attendance> > grouped_attendance;           //map to course ids of vector class
                grouped_attendance = ptr->groupAttendancesByCID(attendances);    //vector as input, return map
                // Display the grouped attendances
                for (const auto &pair : grouped_attendance)   //iterating map of grouped
                {
                    cout << "Course: " << pair.first << ":\n";      //Course ID
                    for (const auto &attendance_i : pair.second)   //each data member
                    {
                        cout << "  Date: " << attendance_i.date
                             << ", Roll Number: " << attendance_i.rollNumber
                             << ", isPresent: " << attendance_i.present << "\n";
                    }
                    cout << endl;
                }
            }
            else if (choice == 2)
            {
                string date;                 //new attendance
                string cid;
                string rollNumber;
                bool isPresent;
                cout << "Enter Date: ";
                cin >> date;
                cin.ignore();
                cout << "Enter Course Id: ";
                cin >> cid;
                cin.ignore();


                //each new variable for validator

                validator temp("course");
                if (!temp.course_validator(courses, cid))        //using validator class here
                {
                    cout << "Enter roll Number of the student: ";
                    cin >> rollNumber;
                    cin.ignore();
                    validator temp2("student");
                    if (!temp2.student_validator(students, rollNumber))      //using student vector class here in course
                    {
                        while (1)
                        {
                            cout << "Present (0 or 1): \n";
                            string input;
                            cin>>input;
                            cin.ignore();
                            if (input == "1" || input == "0")
                            {
                                if (input=="1")
                                    isPresent=1;     //simple bool
                                else
                                    isPresent=0;
                                break;
                            }   
                            else
                            {
                                cout << "Invalid Input!\n";
                            }
                        }
                        attendance new_attendance(date, cid, rollNumber, isPresent);   //new object
                        validator temp3("attendance");
                        if (temp3.attendance_validator(attendances, new_attendance))   //creating new attendance
                        {
                            cout << "Attendance for roll number, " << rollNumber << ", added successfully!\n";
                            //! Save the new attandence to the array
                            attendances.push_back(new_attendance);    //add at end of vector
                        }
                        else
                        {
                            cout << "Attendance for the roll number, " << rollNumber << ", already exisits!\n";
                        }
                    }
                    else
                    {
                        cout << "No such student exists!\n";
                    }
                }
                else                                            //checks
                {
                    cout << "No such course exists\n";
                }
            }
            else
            {
                cout << "Invalid Choice!\n";
            }
            //Update attendance array
            ostringstream result;  //buffer   
            for (int i = 0; i < attendances.size(); i++)
            {
                result << attendances[i].date << ",";
                result << attendances[i].cid << ",";
                result << attendances[i].rollNumber << ",";
                result << attendances[i].present << endl;
            }
            string data = result.str();           //storing back
            fileHandler write("attendance.txt", "write", data);
            write.writeToAttendance();
        }
    }
    void mark_menu(vector<student> &students, vector<course> &courses, vector<mark> &marks)
    {
        fileHandler student_reader("students.txt", "read", "");    //referring to three classes
        fileHandler course_reader("courses.txt", "read", "");
        fileHandler marks_reader("marks.txt", "read", "");
        int choice;
        while (1)
        {
            students = student_reader.readFromStudents();
            courses = course_reader.readFromCourses();
            marks = marks_reader.readFromMarks();
            cout << "Marks Menu!\n";
            cout << "1. Display Marks\n";
            cout << "2. Add Marks For a student\n";
            cout << "0. Back\n";
            cin >> choice;
            if (choice == 0)
                break;
            else if (choice == 1)         //simple display from file
            {
                mark *ptr = nullptr;
                map<string, vector<mark> > grouped_marks;      //map to marks of vector class
                grouped_marks = ptr->groupMarksByCID(marks);    //vector as input, return map
                cout << "Marks of students course-wise: \n";
                for (const auto &pair : grouped_marks)        //iterating map of grouped
                {
                    cout << "Course: " << pair.first << ":\n";   //each data member
                    for (const auto &mark_i : pair.second)
                    {
                        cout << "  Roll Number: " << mark_i.rollNumber << ", Marks: " << mark_i.marks << "\n";
                    }
                    cout << endl;
                }
            }
            else if (choice == 2)
            {
                string cid;                //new mark
                string rollNumber;
                string new_marks;
                cout << "Enter Course Id: ";
                cin >> cid;
                cin.ignore();

                //each new variable for validator
                validator temp("course");
                if (!temp.course_validator(courses, cid))          //using course vector class here 
                {
                    cout << "Enter roll Number of the student: ";
                    cin >> rollNumber;
                    cin.ignore();
                    validator temp2("student");

                    if (!temp2.student_validator(students, rollNumber))
                    {
                        cout << "Enter Marks: ";
                        cin >> new_marks;
                        cin.ignore();
                        mark new_mark(cid, rollNumber, new_marks);      //new obj
                        validator temp3("mark");
                        if (temp3.mark_validator(marks, new_mark))    //following valid check
                        {
                            marks.push_back(new_mark);      //new marks added in vector 
                            cout << "Marks for course, " << cid << ", roll number: " << rollNumber << ", added successfully!\n";
                        }
                        else //simul checking for existence on roll number
                        {
                            cout << "Marks for such course and roll number already exists\n";
                        }
                    }
                    else
                    {
                        cout << "No such student exists!\n";
                    }
                }
                else
                {
                    cout << "No such course exists\n";
                }
            }
            else
            {
                cout << "Invalid input!\n";
            }
            //! Update marks array
            ostringstream result;     //buffer
            for (int i = 0; i < marks.size(); i++)     //updaring in file
            {
                result << marks[i].cid << ",";
                result << marks[i].rollNumber << ",";
                result << marks[i].marks << endl;
            }
            string data = result.str();
            fileHandler write("marks.txt", "write", data);
            write.writeToMarks();
        }
    }
    void course_menu(vector<student> &students, vector<course> &courses)
    {
        fileHandler course_reader("courses.txt", "read", "");
        int choice;
        while (1)
        {
            courses = course_reader.readFromCourses(); //in vector stored
            cout << "Course Menu\n"; 
            cout << "1. Create a new course\n";
            cout << "2. Display Courses\n";
            cout << "3. Register student to a course\n";
            cout << "4. Withdraw student from a course\n";
            cout << "0. Back\n";
            cin >> choice;
            cin.ignore();
            if (choice == 0)
            {
                break;
            }
            else if (choice == 1)
            {
                string code;
                string name;
                string instructor;
                string credits;
                string capacity;
                cout << "Enter course code: ";
                cin >> code;
                cin.ignore();
                cout << "Enter course name: ";
                cin >> name;
                cin.ignore();
                cout << "Enter course instructor: ";
                cin >> instructor;
                cin.ignore();
                cout << "Enter course credits: ";
                cin >> credits;
                cin.ignore();
                cout << "Enter course capacity: ";
                cin >> capacity;
                cin.ignore();
                course new_course(code, name, instructor, credits, capacity);   //new obj
                validator course_validator("course");
                if (course_validator.course_validator(courses, new_course))      //validator check
                {
                    cout << "Course Added Successfully!\n";
                    courses.push_back(new_course);               //storing it in end
                }
                else
                {
                    cout << "Course already exists\n";
                }
            }
            else if (choice == 2)
            {
                cout << "Courses being taught: \n";
                for (int i = 0; i < courses.size(); i++)
                {
                    cout << i + 1 << endl;
                    courses[i].display_course();
                }
            }
            else if (choice == 3)
            {
                string cid;
                string rollNumber;
                cout << "Enter Course Id: ";
                cin >> cid;
                cin.ignore();
                validator temp("course");         //rgistering once check completes
                if (!temp.course_validator(courses, cid))
                {
                    cout << "Enter roll Number of the student: ";
                    cin >> rollNumber;
                    cin.ignore();
                    validator temp2("student");
                    if (!temp2.student_validator(students, rollNumber))    //checking roll no
                    {
                        for (int i = 0; i < courses.size(); i++)
                        {
                            if (cid == courses[i].code)         //bool for same course code
                            {
                                courses[i].student_rollNumbers.push_back(rollNumber);   
                                break;   //adding one more in list through student id
                            }
                        }
                        cout << "Student Register to course id: " << cid << ", successfully!\n";
                    }
                    else
                    {
                        cout << "No such student exists!\n";
                    }
                }
                else
                {
                    cout << "No such course exists\n";
                }
            }
            else if (choice == 4)
            {
                string cid;
                string rollNumber;
                cout << "Enter Course Id: ";
                cin >> cid;
                cin.ignore();
                validator temp("course");
                if (!temp.course_validator(courses, cid))
                {
                    cout << "Enter roll Number of the student: ";
                    cin >> rollNumber;
                    cin.ignore();
                    validator temp2("student");                         //course and student checks
                    if (!temp2.student_validator(students, rollNumber))
                    {
                        for (int i = 0; i < courses.size(); i++)
                        {
                            if (courses[i].code == cid)                 //choice for user to remove which roll no
                            {                                           //same course id so withdraw
                                courses[i].remove_student(rollNumber);
                            }
                        }
                        cout << "Student withdrawn from course id: " << cid << ", successfully!\n";
                    }
                    else
                    {
                        cout << "No such student exists!\n";
                    }
                }
                else
                {
                    cout << "No such course exists\n";
                }
            }
            else
            {
                cout << "Invalid Input\n";
            }
            ostringstream result;     //string buffer
            for (int i = 0; i < courses.size(); i++)
            {
                result << courses[i].code << ",";
                result << courses[i].name << ",";
                result << courses[i].instructor << ",";
                result << courses[i].credits << ",";
                result << courses[i].capacity << ",";
                for (int j = 0; j < courses[i].student_rollNumbers.size(); j++)
                {
                    result << courses[i].student_rollNumbers[j] << ",";
                }                                                        //storing and appending in file
                result << endl;
            }
            string data = result.str();
            fileHandler write("courses.txt", "write", data);
            write.writeToCourses();
        }
    }
    void student_menu(vector<student> &students)
    {
        int choice;
        while (1)
        {
            fileHandler student_reader("students.txt", "read", "");
            students = student_reader.readFromStudents();
            cout << "Student Menu: \n";
            cout << "1. Display already enrolled students\n";
            cout << "2. Add a student\n";
            cout << "3. Remove a student\n";
            cout << "4. Edit student detail\n";
            cout << "0. Back\n";
            cin >> choice;
            cin.ignore();
            if (choice == 1)
            {
                cout << "Enrolled Students:\n";
                for (int i = 0; i < students.size(); i++)
                {
                    cout << i + 1 << endl;
                    students[i].display();
                }
            }
            else if (choice == 2)
            {
                string name;
                string rollNumber;
                string Age;
                string contact;
                cout << "Enter name: ";
                cin >> name;
                cin.ignore();
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                cin.ignore();
                cout << "Enter Age: ";
                cin >> Age;
                cin.ignore();
                cout << "Enter Contact: ";
                cin >> contact;
                cin.ignore();
                student new_student(name, rollNumber, Age, contact);
                validator temp("student");
                if (temp.student_validator(students, new_student))
                {
                    students.push_back(new_student);
                    cout << "Student added successfully!\n";
                }
                else
                {
                    cout << "Student with this roll number already exists!\n";
                }
            }
            else if (choice == 0)
            {
                break;
            }
            else if (choice == 3)
            {
                string rollNumber;
                cout << "Enter roll number of the student: ";
                cin >> rollNumber;
                cin.ignore();
                bool flag = 0;
                for (int i = 0; i < students.size(); i++)
                {
                    if (students[i].compare_rollNumber(rollNumber))
                    {
                        for (int j = i; j < students.size() - 1; j++)
                        {
                            students[j] = students[j + 1];
                        }
                        students.pop_back();
                        cout << "Student with Roll Number, " << rollNumber << ", removed successfully!\n";
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    cout << "No student found with Roll Number, " << rollNumber << endl;
            }
            else if (choice == 4)
            {
                string rollNumber;
                cout << "Enter roll number of the student: ";
                cin >> rollNumber;
                cin.ignore();
                bool flag = 0;
                for (int i = 0; i < students.size(); i++)
                {
                    if (students[i].compare_rollNumber(rollNumber))
                    {
                        string name;
                        string age;
                        string contact;
                        cout << "Enter name: ";
                        cin >> name;
                        cin.ignore();
                        cout << "Enter Age: ";
                        cin >> age;
                        cin.ignore();
                        cout << "Enter Contact: ";
                        cin >> contact;
                        cin.ignore();
                        students[i].update(name, age, contact);
                        cout << "Student with Roll Number, " << rollNumber << ", updated successfully!\n";
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    cout << "No student found with Roll Number, " << rollNumber << endl;
            }
            else
                cout << "Invalid Choice!\n";
            ostringstream result;
            for (int i = 0; i < students.size(); i++)
            {
                result << students[i].name << ",";
                result << students[i].rollNo << ",";
                result << students[i].age << ",";
                result << students[i].contact << endl;
            }
            string data = result.str();
            fileHandler write("students.txt", "write", data);
            write.writeToStudents();
        }
    }
};