#include <iostream>
#include "Person.h"

using namespace std;

//Accessors
string Person::getName(){
    return name;
}

int Person::getID(){
    return id;
}

string Person::getContactInfo(){
    return ContactInfo;
}

//Mutators
void Person::setName(const string& newName){
    this->name = newName;
}

void Person::setID(int newID){
    this->id = newID;
}

void Person::setContactInfo(const string& newContactInfo){
    this->ContactInfo = newContactInfo;
}

//Constructor & Destructor
Person::Person(){}
Person::~Person(){}
