#include <iostream>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Secretary.h"

using namespace std;

//####################################################
//############### DEPARTMENT #########################
//####################################################

//Accessors
string Department::getDepartmentName(){
    return this->DepartmentName;
}

int  Department::getNumberOfSemesters(){
    return this->NumberOfSemesters;
}

int  Department::getECTSforDegree(){
    return this->ECTSforDegree;
}

int Department::getCoreClasses(){
    return this->CoreClasses;
}

//Mutators
void Department::setDepartmentName(string name){
    this->DepartmentName = name;
}

void Department::setNumberOfSemesters(int number){
    this ->NumberOfSemesters=number;
}

void Department::setECTSforDegree(int number){
    this->ECTSforDegree=number;
}

void Department::setCoreClasses(int number){
    this->CoreClasses=number;
}

//####################################################
//############### SECRETARY ##########################
//####################################################

//Accessors

    //Get Functions
vector <Student*>& Secretary::getStudents(){
    return this->students;
}

vector <Professor*>& Secretary::getProfessors(){
    return this->professors;
}

vector <Course*>& Secretary::getCourses(){
    return this->courses;
}

    //Print Functions
void Secretary::printStudents() {
    cout << "\nList of Students:\n";
    
    if (students.empty()) {
        cout << "No students enrolled.\n";
        return;
    }

    for (const auto& student : students) {
        cout << "Name: " << student->getName() << ", ";
        cout << "ID: " << student->getID() << ", ";
        cout << "Contact Info: " << student->getContactInfo() << ", ";
        cout << "Total ECTS: " << student->getTotalECTS() << ", ";
        cout << "Current Semester: " << student->getIsInSemester() << ", ";
        cout << "Core Courses: " << student->getHasCoreClasses() << endl;
    }
}

void Secretary::printProfessors(){
    cout << "\nList of Professors:\n";
    
    if (professors.empty()) {
        cout << "No professors available.\n";
        return;
    }

    for (const auto& professor : professors) {
        cout << "Name: " << professor->getName() << ", ";
        cout << "ID: " << professor->getID() << ", ";
        cout << "Contact Info: " << professor->getContactInfo() << endl;
    }
}

void Secretary::printCourses(){
    cout << "\nList of Courses:\n";
    
    if (courses.empty()) {
        cout << "No courses available.\n";
        return;
    }

    for (const auto& course : courses) {
        cout << "Course Name: " << course->getCourseName() << ", ";
        cout << "ECTS: " << course->getECTS() << ", ";
        cout << "Selective: " << (course->getIsSelective() ? "Yes" : "No") << ", ";
        cout << "Semester: " << course->getSemester() << endl;
    }
}

void Secretary::GeneralInfo(){

    secretary.ReadDepartmentInfoFromFile("INPUT/departmentInfo.txt");
    string name = secretary.getDepartmentName();
    int ects = secretary.getECTSforDegree();
    int semesters = secretary.getNumberOfSemesters();
    int coreClasses = secretary.getCoreClasses();

    cout << "\nThe Department of " << name <<  " is currently home to: \n" << endl;
    cout <<"STUDENTS"<< "\t"<<"PROFESSORS"<< endl;
    cout << "   " << Student::NumberOfStudents << "\t\t    " << Professor::NumberOfProfessors << endl;
    cout << endl;
    cout << "And Provides: \n" << endl;
    cout << "       " << " COURSES" << endl;
    cout << "\t   " << Course::NumberOfCourses << endl;
    cout << "\nStudent's need at least " << ects << " ECTS's, ";
    cout << "and to have passed \n" << coreClasses << " core classes to graduate, ";
    cout << "in the span of " << semesters << "  or more academic semesters." << endl;
}

//Mutators
    
    //Add Functions
void Secretary::AddStudent(){

    string name, contactInfo;
    int id,TotalECTS,year, core;

    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter student contact info: ";
    cin >> contactInfo;

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student's ECTS so far: ";
    cin >> TotalECTS;

    cout << "Enter student's current Semester: ";
    cin >> year;

    cout << "Enter student's number of core Courses passed: ";
    cin >> core;

    // Create a new Student object with the provided information
    Student* newStudent = new Student();
    newStudent->setName(name);
    newStudent->setID(id);
    newStudent->setContactInfo(contactInfo);
    newStudent->setTotalECTS(TotalECTS);
    newStudent->setIsInSemester(year);
    newStudent->setHasCoreCourses(core);

    // Add the new student to the vector of students
    students.push_back(newStudent);
    UpdateStudentsFile("OUTPUT/UPDATED_TXT/new_students.txt");
    cout << "Student added successfully!" << endl;
}

void Secretary::AddProfessor(){
    string name, contactInfo;
    long int id;

    cout << "Enter professor name: ";
    cin >> name;

    cout << "Enter professor contact info: ";
    cin >> contactInfo;

    cout << "Enter professor ID: ";
    cin >> id;

    // Create a new Professor object with the provided information
    Professor* newProfessor = new Professor();
    newProfessor->setName(name);
    newProfessor->setID(id);
    newProfessor->setContactInfo(contactInfo);

    // Add the new professor to the vector of professors
    professors.push_back(newProfessor);
    UpdateProfessorsFile("OUTPUT/UPDATED_TXT/new_professors.txt");
    cout << "Professor added successfully!" << endl;
}

void Secretary::AddCourse(){
    string courseName;
    int ECTS;
    bool isSelective;
    int semester;

    cout << "Enter course name: ";
    cin >> courseName;

    cout << "Enter ECTS for the course: ";
    cin >> ECTS;

    cout << "Is the course selective? (1 for Yes, 0 for No): ";
    cin >> isSelective;

    cout << "Enter semester for the course: ";
    cin >> semester;

    // Create a new Course object with the provided information
    Course* newCourse = new Course();
    newCourse->setCourseName(courseName);
    newCourse->setECTS(ECTS);
    newCourse->setIsSelective(isSelective);
    newCourse->setSemester(semester);

    // Add the new course to the vector of courses
    courses.push_back(newCourse);
    UpdateCourseFile("OUTPUT/UPDATED_TXT/new_courses.txt");
    cout << "Course added successfully!" << endl;
}

    //Remove Functions
void Secretary::RemoveStudent(){
    string name;
    cout << "Enter student name to remove: ";
    cin >> name;

    vector<Student*>::iterator it = students.begin();
    for (; it != students.end(); ++it){

        if ((*it)->getName() == name){
            break;  // Student found
        }
    }

    // If the student is found, remove from vector and delete the object
    if(it != students.end()){
        cout << "Removing student with name: " << name << endl;
        delete *it;
        students.erase(it);
        UpdateStudentsFile("OUTPUT/UPDATED_TXT/new_students.txt");
        cout << "Student removed successfully!" << endl;
    }
    else{
        cout << "Student with name " << name << " not found." << endl;
    }
}

void Secretary::RemoveProfessor(){
    string name;
    cout << "Enter professor name to remove: ";
    cin >> name;

    vector<Professor*>::iterator it = professors.begin();
    for (; it != professors.end(); ++it) {
        if ((*it)->getName() == name) {
            break;  // Professor found
        }
    }

    // If the professor is found, remove from vector and delete the object
    if (it != professors.end()) {
        cout << "Removing professor with name: " << name << endl;
        delete *it;
        professors.erase(it);
        UpdateProfessorsFile("OUTPUT/UPDATED_TXT/new_professors.txt");
        cout << "Professor removed successfully!" << endl;
    }
    else{
        cout << "Professor with name " << name << " not found." << endl;
    }
}

void Secretary::RemoveCourse(){
    string courseName;
    cout << "Enter course name to remove: ";
    cin >> courseName;

    vector<Course*>::iterator it = courses.begin();
    for (; it != courses.end(); ++it) {
        if ((*it)->getCourseName() == courseName) {
            break;  // Course found
        }
    }

    // If the course is found, remove from vector and delete the object
    if (it != courses.end()){
        cout << "Removing course with name: " << courseName << endl;
        delete *it;
        courses.erase(it);
        UpdateCourseFile("OUTPUT/UPDATED_TXT/new_courses.txt");
        cout << "Course removed successfully!" << endl;
    }
    else{
        cout << "Course with name " << courseName << " not found." << endl;
    }
}

    //Read Functions
void Secretary::ReadProfessorsFromFile(const string& filename){
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string name;
    string ContactInfo;
    int id;
    while (file >> name >> ContactInfo >> id){
        Professor* newProfessor = new Professor();
        newProfessor->setName(name);
        newProfessor->setContactInfo(ContactInfo);
        newProfessor->setID(id);

        professors.push_back(newProfessor);
    }

    file.close();
}

void Secretary::ReadStudentsFromFile(const string& filename){
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string studentName;
    string contactInfo;
    int studentID, studentECTS, studentSemester, studentCoreCourses;

    while (file >> studentName >> contactInfo >> studentID >> studentECTS >> studentSemester >> studentCoreCourses) {
        Student* newStudent = new Student();
        newStudent->setName(studentName);
        newStudent->setContactInfo(contactInfo);
        newStudent->setID(studentID);
        newStudent->setTotalECTS(studentECTS);
        newStudent->setIsInSemester(studentSemester);
        newStudent->setHasCoreCourses(studentCoreCourses);

        students.push_back(newStudent);
    }

    file.close();
}

void Secretary::ReadDepartmentInfoFromFile(const string& filename){
    ifstream file(filename); // Changed ofstream to ifstream

    if (!file.is_open()) {
        cerr << "Error: Unable to open file..." << endl;
        return;
    }

    string name;
    int number;
    int ects;
    int core;

    while (file >> name >> number >> ects >> core){
        secretary.setDepartmentName(name);
        secretary.setNumberOfSemesters(number);
        secretary.setECTSforDegree(ects);
        secretary.setCoreClasses(core);
    }

    file.close();

    //cout << "Department Info Initialized!" << endl;
}

void Secretary::ReadCoursesFromFile(const string& filename){
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string courseName;
    int ECTS;
    bool isSelective;
    int semester;

    while (file >> courseName >> ECTS >> isSelective >> semester) {
        Course* newCourse = new Course();
        newCourse->setCourseName(courseName);
        newCourse->setECTS(ECTS);
        newCourse->setIsSelective(isSelective);
        newCourse->setSemester(semester);

        courses.push_back(newCourse);
    }

    file.close();
}

    //Update Functions
void Secretary::UpdateCourseFile(const string& filename){
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for updating." << endl;
        return;
    }

    for (const auto& course : courses) {
        file << course->getCourseName() << " ";
        file << course->getECTS() << " ";
        file << course->getIsSelective() << " ";
        file << course->getSemester() << endl;
    }

    file.close();
    cout << "Course file updated successfully!" << endl;
}

void Secretary::UpdateStudentsFile(const string& filename){
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for updating." << endl;
        return;
    }

    for (const auto& student : students) {
        file << student->getName() << " ";
        file << student->getContactInfo() << " ";
        file << student->getID() << " ";
        file << student->getTotalECTS() << " ";
        file << student->getIsInSemester() << endl;
    }

    file.close();
    cout << "Student file updated successfully!" << endl;
}

void Secretary::UpdateProfessorsFile(const string& filename){
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for updating." << endl;
        return;
    }

    for (const auto& professor : professors) {
        file << professor->getName() << " ";
        file << professor->getContactInfo() << " ";
        file << professor->getID() << endl;
    }

    file.close();
    cout << "Professor file updated successfully!" << endl;
}


//##################################################################################################################################
//################################################### SIMULATION FUNCTIONS #########################################################
//##################################################################################################################################

    //For Professors
void Secretary::AssignCoursesToProfessors(){
    for (auto& professor : professors) {
        // Randomly assign a course to the professor
        if (!courses.empty()){
            //generate random index
            int randomIndex = rand() % courses.size();
            professor->TeachingCourses.push_back(courses[randomIndex]);
        }
    }
    cout << "Courses assigned to Professors for the semester!" << endl;
}

//Prints in terminal
void Secretary::PrintProfessorsCourses(){
    for (const auto& professor : professors){
        cout << "Professor " << professor->getName() << " is teaching: ";
        professor->PrintTeachingCourses();
        cout << endl;
    }
}

void Secretary::ProfessorStatistics(){
    // Open a file to write professor statistics
    ofstream outputFile("OUTPUT/Professor_Statistics.txt");

    if (!outputFile.is_open()){
        cerr << "Error: Unable to open output file for writing." << endl;
        return;
    }

    // Iterate through all professors
    for (const auto& professor : professors) {
        outputFile << "Professor: " << professor->getName() << endl;

        // Check if the professor has any teaching courses
        if(professor->TeachingCourses.empty()){
            outputFile << "No courses assigned to this professor." << endl;
        }
        else{
            // Iterate through all teaching courses of the professor
            for (const auto& course : professor->TeachingCourses) {
                int enrolledStudents = 0;
                int passedStudents = 0;

                // Count the number of students enrolled in the course
                for(const auto& student : students){
                    for (const auto& enrolledCourse : student->EnrolledCourses) {
                        if (enrolledCourse == course) {
                            enrolledStudents++;
                            break; // Move to the next student
                        }
                    }
                }

                // Count the number of students who passed the course
                for (const auto& student : students){
                    for (const auto& report : student->ReportCard){
                        if (report->getCourseName() == course->getCourseName() && report->getGrade() >= 50) {
                            passedStudents++;
                            break; // Move to the next student
                        }
                    }
                }

                // Calculate the percentage of students who passed the course. *FANCY WAY*
                double passPercentage = (enrolledStudents != 0) ? (static_cast<double>(passedStudents) / enrolledStudents) * 100.0 : 0.0;

                // Write course statistics to the output file
                outputFile << "Course: " << course->getCourseName() << endl;
                outputFile << "Number of enrolled students: " << enrolledStudents << endl;
                outputFile << "Percentage of students who passed: " << fixed << setprecision(2) << passPercentage << "%" << endl;
            }
        }
        outputFile << endl;
    }

    // Close the output file
    outputFile.close();
    cout << "Professor statistics have been written to ""OUTPUT/Professor_Statistics.txt"" " << endl;
}

    //For Students
void Secretary::EnrollStudentsToCourses(){
    for (auto& student : students){
        for (const auto& course : courses){
            // Enroll student in courses from the current semester or older
            if (course->getSemester() <= student->getIsInSemester()){
                student->EnrolledCourses.push_back(course);
            }
        }
    }
    cout << "Students enrolled in courses for the semester!" << endl;
}

//Prints on termianl
void Secretary::PrintEnrolledStudens(){
    for(const auto& student : students){
        cout << "Student " << student->getName();
        cout << ", Semester: "<<student->getIsInSemester();
        cout << ", enrolled in:" << endl;
        student->PrintEnrolledCourses();
    }
}

void Secretary::GradeStudents(){
    for(const auto& student : students){
        //helper function
        student->SetReportCard();
    }
    cout << "Students Graded!" << endl;
}

//Prints on terminal
void Secretary::PrintGradedStudents(){
    for( const auto& student : students){
        //helper function
        student->ReadReportCard();
    }
    cout << endl;
}

//This Function outputs the reports of every Student
void Secretary::FileStudentsGrades(){
    const std::string outputFolder = "OUTPUT/STUDENTS_REPORTS";

    for (const auto& student : students){
        // Create a file named after the student's name in the OUTPUT folder. needs check
        std::string filename = outputFolder + "/" + student->getName() + "_ReportCard.txt";
        std::ofstream file(filename);

        if(!file.is_open()){
            std::cerr << "Error: Unable to open file for updating: " << filename << std::endl;
            // Continue to the next student if file opening fails
            continue;
        }

        file << student->ReadReportCard();

        file.close();
        //cout << "Student file updated successfully: " << filename << endl;
    }
    cout << "Student's Reports have been extracted to ""OUTPUT/STUDENTS_REPORTS"" " << endl;
}

//Outputs Students who passed given course
void Secretary::StudentsPassedCourse(const string& courseName){
    // Open a file to write the list of students who passed the course
    ofstream outputFile("OUTPUT/Students_Passed_" + courseName + ".txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file for writing." << endl;
        return;
    }

    // Iterate through all students
    for(const auto& student : students){
        // Search for the specified course in the student's report card
        for(const auto& report : student->ReportCard){
            if(report->getCourseName() == courseName && report->getGrade() >= 50){
                // Write the student's name and grade to the output file
                outputFile << "Student Name: " << student->getName() << ", Grade: " << report->getGrade() << endl;
                break; // Move to the next student after finding the course
            }
        }
    }

    // Close the output file
    outputFile.close();
    cout << "Students who passed course \"" << courseName << "\" have been written to file." << endl;
}

//Updates students file after simulation
void Secretary::WriteUpdatedStudentInfo(){
    ofstream outputFile("OUTPUT/UPDATED_TXT/UPDATED_STUDENT_INFO.txt");

    if(!outputFile.is_open()){
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    outputFile << "Updated Student Information:\n";

    for(const auto& student : students){
        outputFile << "Name: " << student->getName() << ", ";
        outputFile << "ID: " << student->getID() << ", ";
        outputFile << "Total ECTS: " << student->getTotalECTS() << ", ";
        outputFile << "Semester: " << student->getIsInSemester() << ", ";
        outputFile << "Core Courses: " << student->getHasCoreClasses() << endl;
    }

    outputFile.close();
}


void Secretary::EligibleForDegree(){
    ofstream outputFile("OUTPUT/Eligible_For_Degree.txt");

    if(!outputFile.is_open()){
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    outputFile << "Students Eligible for Degree:\n";

    for(const auto& student : students){
        if (student->getTotalECTS() >= getECTSforDegree() &&
            student->getIsInSemester() >= getNumberOfSemesters() &&
            student->getHasCoreClasses() >= getCoreClasses()){

            outputFile << "Name: " << student->getName() << ", ";
            outputFile << "ID: " << student->getID() << ", ";
            outputFile << "Total ECTS: " << student->getTotalECTS() << ", ";
            outputFile << "Semester: " << student->getIsInSemester() << ", ";
            outputFile << "Core Classes: " << student->getHasCoreClasses() << endl;
        }
    }

    outputFile.close();
    cout << "Students eligible for degree can be found in ""OUTPUT/Eligible_For_Degree.txt"" " << endl; 
}

//Constructor & Destructor
Secretary::Secretary(){};
//Destructor, Frees Memory
Secretary::~Secretary(){

    for(long unsigned int  i = 0; i < students.size(); i++ ){
        delete students[i];
    }
    students.clear();

    for(long unsigned int  j = 0; j < professors.size(); j++ ){
        delete professors[j];
    }
    professors.clear();

    for(long unsigned int k = 0; k < courses.size(); k++ ){
        delete courses[k];
    }
    courses.clear();

    //cout << "Secretary Destroyed..." << endl;
};
