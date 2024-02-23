#include <iostream>
#include "Course.h"

using namespace std;

int Course::NumberOfCourses = 0;

//Accessors
string Course::getCourseName(){
    return CourseName;
}

int Course::getECTS(){
    return ECTS;
}

bool Course::getIsSelective(){
    //cout << "Is Selective: " << (isSelective ? "Yes" : "No") << endl;
    return IsSelective;
}

int Course::getSemester(){
    return Semester;
}

//Mutators
void Course::setCourseName(string name){
    this->CourseName = name;
}

void Course::setECTS(int ects){
    this->ECTS = ects;
}

void Course::setIsSelective(bool i){
    this->IsSelective = i;
}

void Course::setSemester(int semester){
    this->Semester = semester;
}

void Course::moveSemester(int newSemester){
    cout << "Moving course " << CourseName;
    cout << " from Semester " << Semester;
    cout << " to Semester " << newSemester << endl;
    Semester = newSemester;
}

int Report::getGrade(){
    return grade;
}

void Report::setGrade(int grade){
    this->grade=grade;
}