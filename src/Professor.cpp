#include <iostream>
#include "Person.h"

using namespace std;

//Accessors
void Professor::PrintTeachingCourses(){
    for (const auto& course : TeachingCourses) {
        cout << course->getCourseName() << " ";
    }
    cout << endl;
}

//for GeneralInfo()
int Professor::NumberOfProfessors = 0;
