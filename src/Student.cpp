#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Person.h"

using namespace std;

//for GeneralInfo()
int Student::NumberOfStudents = 0;

//Accessors
int Student::getTotalECTS(){
    return this->TotalECTS;
}

int Student::getIsInSemester(){
    return this-> IsInSemester;
}

int Student::getHasCoreClasses(){
    return this->HasCoreCourses;
}

void Student::PrintEnrolledCourses(){
    for (const auto& course : EnrolledCourses){
        cout << course->getCourseName() << ", Semester: " << course->getSemester();
        cout << ", ECTS: " << course->getECTS() << endl;
    }
    cout << endl;
}

//Mutators
void Student::setTotalECTS(int ects){
    this -> TotalECTS = ects;
}

void Student::setIsInSemester(int semester){
    this-> IsInSemester = semester;
}

void Student::setHasCoreCourses(int courses){
    this->HasCoreCourses = courses;
}

//Helper function to grade students
void Student::SetReportCard() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (const auto& course : EnrolledCourses){

        Report* report = new Report();
        report->setCourseName(course->getCourseName());
        report->setECTS(course->getECTS());
        report->setIsSelective(course->getIsSelective());
        report->setSemester(course->getSemester());

        //give random grade between 20 and 100
        int grade = std::rand() % 81 + 20;
        report->setGrade(grade);

        //Increment HasCoreCourses if the course is selective and the student has passed it
        if (course->getIsSelective() && grade >= 50) {
            HasCoreCourses++;
        }

        //Increment student's total ECTS by the course's ECTS if the student passes the course
        if (grade >= 50) {
            TotalECTS += course->getECTS();
        }

        ReportCard.push_back(report);
    }
}

//This function prints the data in the student's Report card
string Student::ReadReportCard(){
    stringstream ss;
    int c=1;
    ss << getName() << "'s Report Card:\n";
    for (const auto& report : ReportCard){
        ss << c << ".";
        ss << "Course: " << report->getCourseName();
        ss << ", Grade: " << report->getGrade();
        ss << ", ECTS: " << report->getECTS() << "\n";
        c++;
    }
    ss << endl;

    return ss.str();
}