#include <iostream>
#include <vector>

using namespace std;

class Course{

    //To give access to the constructor to increment or decrease 
    //the number of courses for secreatary.generalInfo()
    friend class Secretary;
    friend int main();

    private:
        string CourseName;
        int ECTS;
        bool IsSelective;
        int Semester;

    public:
        static int NumberOfCourses;
        //Accessors
        string getCourseName();
        int getECTS();
        bool getIsSelective();
        int getSemester();
        int getNumberOfCourses();

        //Mutators
        void setCourseName(string name);
        void setECTS(int ects);
        void setIsSelective(bool i);
        void setSemester(int semster);
        void moveSemester(int newSemester);

        //Constructor & Destructor
    protected:
        // Protected constructor, accessible to derived classes but doesn't increment counter
        Course(bool incrementCounter = true){
            if (incrementCounter) {
                NumberOfCourses++;
            }
        }
    public:
    ~Course(){NumberOfCourses--;}
};

class Report: public Course{
    private:
        int grade;
    public:
        //Accessor and Mutator
        int getGrade();
        void setGrade(int grade);

        //Custom Constructor
        //so that it won't increment "NumberOfCourses" in Student::SetReportCard();
        Report() : Course(false){};
};