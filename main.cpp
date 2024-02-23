#include <iostream>
#include <vector>
#include "Secretary.h"
#include "menu.h"

//has been declared extern in include/Secretary.h
Secretary secretary;

using namespace std;

int main(void){


        //INITIALIZE SECRETARY VARIABLES FROM .TXT FILES
        secretary.ReadCoursesFromFile("INPUT/courses.txt");
        secretary.ReadProfessorsFromFile("INPUT/professors.txt");
        secretary.ReadStudentsFromFile("INPUT/students.txt");
        secretary.ReadDepartmentInfoFromFile("INPUT/departmentInfo.txt");
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Initialized Courses, Students & Professors! (from .txt files)" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;


    //################################################
    //THIS IS AN EXAMPLE OF A COURSE CHANGING SEMESTER
    //################################################
    /*{
        Course math;
        math.setCourseName("Math");
        math.setSemester(2);
        cout <<"Course: " << math.getCourseName() << ", semester: " << math.getSemester() << endl;
        math.setSemester(5);
        cout <<"Course: " << math.getCourseName() << ", semester: " << math.getSemester() << endl;
    }*/

    int userInput;

    //CODE FOR printMenu() AND InputManagement() IS IN src/menu.cpp
    printMenu();
    do{
        cout << "-----------------------------------------------------" << endl;
        cout << "INPUT: ";

        cin >> userInput;
        InputManagement(userInput);
        
        cout << endl;
    }while(userInput!=0);

    return 0;
}