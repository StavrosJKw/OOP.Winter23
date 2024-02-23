#include <iostream>
#include <chrono>
#include <thread>
#include "Secretary.h"
#include "menu.h"

using namespace std;

//Print Menu Function
void printMenu(){
    cout << "-----------------------------------------------------" << endl;
    cout << "\n#################################################" << endl;
    cout << "############# University Secretary ##############" << endl;
    cout << "#################################################\n" << endl;

    cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
    cout << endl;

    cout << "0. To exit" << endl;
    cout << "11.Choices Reminder" << endl;

    cout << "//" << endl;
    cout << "1. Add Student" << "\t\t" << "4. Add Professor" << "\t" << "7. Add Course" << endl;
    cout << "2. Delete Student" << "\t" << "5. Delete Professor" << "\t" << "8. Delete Course" << endl;
    cout << "3. Print Students" << "\t" << "6. Print Professors" << "\t" << "9. Print Courses" << endl;

    cout << "//" << endl;
    cout << "12.General Info" << endl;
    //cout << "13.Initialize Variables" << endl;
    cout << "\n10.*SEMESTER SIMULATION*" << endl;
}

//Manage the User's Input
void InputManagement(int input){

    switch(input){

        case 0:
            PrintGoodbye();
            return;
//-------------------------------------------
        case 1:
            secretary.AddStudent();
            break;
        case 2:
            secretary.RemoveStudent();
            break;
        case 3:
            secretary.printStudents();
            break;
//-------------------------------------------
        case 4:
            secretary.AddProfessor();
            break;
        case 5:
            secretary.RemoveProfessor();
            break;
        case 6:
            secretary.printProfessors();
            break;
//-------------------------------------------
        case 7:
            secretary.AddCourse();
            break;
        case 8:
            secretary.RemoveCourse();
            break;
        case 9:
            secretary.printCourses();
            break;
//-------------------------------------------
        case 12:
            secretary.GeneralInfo();
            break;
//-------------------------------------------
        case 10:
            secretary.AssignCoursesToProfessors();
            //secretary.PrintProfessorsCourses();

            secretary.EnrollStudentsToCourses();
            //secretary.PrintEnrolledStudens();

            secretary.GradeStudents();
            //secretary.PrintGradedStudents();
            secretary.FileStudentsGrades();
            secretary.StudentsPassedCourse("Game_Development");
            
            secretary.ProfessorStatistics();
            secretary.WriteUpdatedStudentInfo();
            secretary.EligibleForDegree();
            break;
            
        case 11: 
            printMenu();
            break;
    }
}

//Just for fun
void PrintGoodbye(){

    cout << "End of Program";
    for(int i=0; i<2; ++i){
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout.flush();
    }
    cout << "Goodbye!";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl;
};