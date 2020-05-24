#include <string>
#include "AttendanceRecord.h"
#include "Date.h"

using namespace std;

  AttendanceRecord::AttendanceRecord(std::string c_id, std::string s_id, Date T):
      course_id(c_id),
      student_id(s_id),
      time(T)
      {
      }
  string AttendanceRecord::getCourseID(){
        return course_id;
  }
  string AttendanceRecord::getStudentID(){
        return student_id;
  }
  Date AttendanceRecord::getDate(){
        return time;
  }

