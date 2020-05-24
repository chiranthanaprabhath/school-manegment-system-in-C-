#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;


void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);

    if (!ss.fail()) {
        bool flag = true;
        for(int i=0; i < students.size(); i++){
            if(students[i].get_id()==uin && students[i].get_name()==name){
                flag=false;
            }
        }
        if(flag){
            students.push_back(Student(uin, name));
        }
    }
  }
}
void School::addCourses(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string id;
    getline(ss, id, ',');
    string startTimeString;
    getline(ss, startTimeString,',');
    string endTimeString;
    getline(ss, endTimeString,',');
    string title;
    getline(ss, title);
    if (!ss.fail()) {

        int H, M,S;
        sscanf(startTimeString.c_str(), "%d:%d:%d", &H, &M,&S);
        Date startTime = Date(H,M,S);
        sscanf(endTimeString.c_str(), "%d:%d:%d", &H, &M,&S);
        Date endTime = Date(H,M,S);
        bool flag = true;
        for(int i=0; i < courses.size(); i++){
            if(courses[i].getID()==id && courses[i].getTitle()==title){
                flag=false;
            }
        }
        if(flag){
           courses.push_back(Course(id,title,startTime,endTime));
        }

    }
  }
}

void School::addAttendanceData(string filename) {
   ifstream ifs(filename);
   if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
   }
   while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        istringstream ss(line);
        string time;
        getline(ss, time, ',');
        string course_id;
        getline(ss, course_id,',');
        string student_id;
        getline(ss, student_id);
        if (!ss.fail()) {
            int H, M,Y,D,Month,S;
            bool flag=true;
            sscanf(time.c_str(), "%d-%d-%d %d:%d:%d", &Y,&Month,&D,&H,&M,&S);
            Date Time = Date(Y,Month,D,H,M,S);
            for(int i=0;i<courses.size();i++){
                if(courses[i].getID()==course_id){
                    courses[i].addAttendanceRecord(AttendanceRecord(course_id,student_id,Time));
                    flag=false;
                }
            }
            if(flag){
                cout<<"did not save this record."<< endl;
            }
    }
  }

}

void School::outputCourseAttendance (string courseId) {
    if(courses.size()>0){
        bool flag=true;
        if(flag){
            for(int i=0;i<courses.size();i++){
            if(courses[i].getID()==courseId){
                courses[i].outputAttendance();
                flag=false;
            }
        }

        }
                if(flag){
                cout<<"No Records"<< endl;
        }
        }

    else{
        cout<<"No Records"<< endl;
    }
    }





void School::outputStudentAttendance (string studentId,string courseId) {
    if(courses.size()>0){
            bool flag=true;
            if(flag){
                       for(int i=0;i<courses.size();i++){
            if(courses[i].getID()==courseId){
                courses[i].outputAttendance(studentId);
                flag=false;
            }
        }
            }

        if(flag){
                cout<<"No Records"<< endl;
        }
        }
            else{
        cout<<"No Records"<< endl;
        }
}
void School::listStudents () {
    if(students.size()==0){
        cout << "No Students" << endl;;
    }
    else{
      for(int i=0; i < students.size(); i++){
        string id=  students.at(i).get_id();
        string name=  students.at(i).get_name();
        cout << id << "," << name <<endl;
      }

    }

}

void School::listCourses () {
    if(courses.size()==0){
        cout << "No Courses" << endl;;
    }
    else{
      for(int i=0; i < courses.size(); i++){
        string id=  courses.at(i).getID();
        string strat_time=  courses.at(i).getStartTime().getTime(false);
        string end_time=  courses.at(i).getEndTime().getTime(false);
        string title=  courses.at(i).getTitle();
        cout << id << "," << strat_time<< ","<<end_time<< ","<<title<<endl;
      }

    }
}

