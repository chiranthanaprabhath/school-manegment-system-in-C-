#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id,string student_name){
    id=student_id;
    name=student_name;
}
void Student::addCourse(string course_id) {
 course_ids.push_back(course_id);
}
void Student::listCourses() {
    for(int i=0;course_ids.size();i++){
       cout<<course_ids[i];
    }
}
string Student::get_id() {
    return id;
}
string Student::get_name(){
    return name;
}
