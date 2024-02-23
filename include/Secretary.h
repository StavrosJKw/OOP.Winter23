#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

class Department{
    private:
        string DepartmentName;
        int NumberOfSemesters;
        int ECTSforDegree;
        int CoreClasses;
    public:
        //Accessors
        string getDepartmentName();
        int getNumberOfSemesters();
        int getECTSforDegree();
        int getCoreClasses();

        //Mutators
        void setDepartmentName(string name);
        void setNumberOfSemesters(int number);
        void setECTSforDegree(int number);
        void setCoreClasses(int number);
};

class Secretary: public Department{
    private:
        //Secretary has Students, Professors & Courses
        vector <Student*> students;
        vector <Professor*> professors;
        vector <Course*> courses;
    public:
        //Accessors
        vector <Student*>& getStudents();
        vector <Professor*>& getProfessors();
        vector <Course*>& getCourses();

        void printStudents();
        void printProfessors();
        void printCourses();

        void GeneralInfo();

        //Mutators
        void AddStudent();
        void AddProfessor();
        void AddCourse();

        void RemoveStudent();
        void RemoveProfessor();
        void RemoveCourse();

        //Read & Update
        void ReadCoursesFromFile(const string& filename);
        void ReadProfessorsFromFile(const string& filename);
        void ReadStudentsFromFile(const string& filename);
        void ReadDepartmentInfoFromFile(const string& filename);

        void UpdateCourseFile(const string& filename);
        void UpdateStudentsFile(const string& filename);
        void UpdateProfessorsFile(const string& filename);

        //Simulation

            //For Professors
        void AssignCoursesToProfessors();
        void PrintProfessorsCourses();
        void ProfessorStatistics();

            //For Students
        void EnrollStudentsToCourses();
        void PrintEnrolledStudens();

        void GradeStudents();
        void PrintGradedStudents();
        void FileStudentsGrades();

        void StudentsPassedCourse(const string& courseName);
        void WriteUpdatedStudentInfo();
        
        void EligibleForDegree();

        //Constructor & Destructor
        Secretary();
        ~Secretary();
};

//This is the secretary object that the program uses for functions and the simulation
extern Secretary secretary;
