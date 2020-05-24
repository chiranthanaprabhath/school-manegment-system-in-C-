#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;


  Course::Course(std::string course_id, std::string course_title, Date course_startTime, Date course_endTime):

      id(course_id),
      title(course_title),
      startTime(course_startTime),
      endTime(course_endTime)
  {}
  string Course::getID(){
      return id;
  }
  string Course::getTitle(){
      return title;
  }
  Date Course::getStartTime(){
      return startTime;
  }
  Date Course::getEndTime(){
      return endTime;
  }
  void Course::addAttendanceRecord(AttendanceRecord ar){
     if(ar.getDate()>=startTime && ar.getDate()<endTime){
        attendanceRecords.push_back(ar);
     }
     else{
        cout<<"did not save this record."<< endl;
     }

  }
  void Course::outputAttendance(){
      if(attendanceRecords.size()>0){
                for(int i=0;i<attendanceRecords.size();i++){
            cout<<attendanceRecords[i].getDate().getDateTime() <<","<<attendanceRecords[i].getCourseID()<<","<<attendanceRecords[i].getStudentID()<< endl;
        }
      }

        else{
            cout<<"No Record"<< endl;
        }
  }
  void Course::outputAttendance(std::string student_id){
      bool flag=true;
        for(int i=0;i<attendanceRecords.size();i++){
            if(attendanceRecords[i].getStudentID()==student_id){
                 cout<<attendanceRecords[i].getDate().getDateTime() <<","<<attendanceRecords[i].getCourseID()<<","<<attendanceRecords[i].getStudentID()<< endl;
                flag=false;
            }


        }
        if(flag){
            cout<<"No Record" << endl;
        }
  }
