#include <iostream>
#include <vector>
#include "Course.h"

using namespace std;

class Person{
    private:
        string name;
        int id;
        string ContactInfo;
    public:
        //Accessors
        string getName();
        int getID();
        string getContactInfo();

        //Mutators
        void setName(const string& newName);
        void setID(int newID);
        void setContactInfo(const string& newContactInfo);

        //Constructor & Destructor
        Person();
        ~Person();
};

class Student:public Person{
    private:
        int TotalECTS;
        int IsInSemester;
        int HasCoreCourses;

    public:
        static int NumberOfStudents;
        vector <Course*> EnrolledCourses;

        //Accessors
        int getTotalECTS();
        int getIsInSemester();
        int getHasCoreClasses();
        void PrintEnrolledCourses();

        //Mutators
        void setTotalECTS(int ects);
        void setIsInSemester(int semester);
        void setHasCoreCourses(int courses);

        //Report Card of the Student
        vector <Report*> ReportCard;
        
        //Accessor & Mutator
        string ReadReportCard();
        void SetReportCard();

        //Constructor & Destructor
        Student(){NumberOfStudents++;}
        ~Student(){
            NumberOfStudents--;
            //free the memory of the report class
            for(long unsigned int l=0; l < ReportCard.size(); l++){
                delete ReportCard[l];
            }
            ReportCard.clear();
        }
};

class Professor:public Person{
    public:
        static int NumberOfProfessors;
        vector <Course*> TeachingCourses;

        //Accessors
        void PrintTeachingCourses();

        //Constructor & Destructor
        Professor(){NumberOfProfessors++;}
        ~Professor(){NumberOfProfessors--;}
};

