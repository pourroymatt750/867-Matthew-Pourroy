//
//  roster.cpp
//
//  Created by Matthew Pourroy on 10/9/22.
//

#include "roster.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void Roster::add(string id, string firstName, string lastName, string email, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram program) {
    int daysArr[3] = { courseDays1, courseDays3, courseDays3 };
    classRosterArray[++lastIdx] = new Student(id, firstName, lastName, email, age, daysArr, program);
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->Student::Print();
        }
    }
}

void Roster::parse(std::string data) {
    //Parses id
    size_t rhs = data.find(",");
    string id = data.substr(0, rhs);
    
    //Parses first name
    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);
    
    //Parses last name
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);
    
    //Parses email
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string email = data.substr(lhs, rhs - lhs);
    
    //Parses age
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));
    
    //Parses days in first course
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int courseDays1 = stoi(data.substr(lhs, rhs - lhs));
    
    //Parses days in second course
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int courseDays2 = stoi(data.substr(lhs, rhs - lhs));
    
    //Parses days in third course
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int courseDays3 = stoi(data.substr(lhs, rhs - lhs));
        
    //Parses degree program
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string degreeType = data.substr(lhs, rhs - lhs);
    
    DegreeProgram program;
    if (degreeType == "SECURITY") {
        program = DegreeProgram::SECURITY;
    }
    if (degreeType == "NETWORK") {
        program = DegreeProgram::NETWORK;
    }
    if (degreeType == "SOFTWARE") {
        program = DegreeProgram::SOFTWARE;
    }
    
    Roster::add(id, firstName, lastName, email, age, courseDays1, courseDays2, courseDays3, program);
}

void Roster::printInvalidEmails() {
    for (int i=0; i < 5; i++) {
        string emailAddress = classRosterArray[i]->GetEmail();
        
        if ((emailAddress.find(' ') != string::npos) || (emailAddress.find('.') == string::npos)
            || (emailAddress.find('@') == string::npos)) {
            cout << emailAddress << " is invalid.";
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string id) {
    for (int i=0; i < 5; i++) {
        if (classRosterArray[i]->Student::GetId() == id) {
            int* daysArr = classRosterArray[i]->Student::GetDaysArr();
            int avgDays = (daysArr[0] + daysArr[1] + daysArr[2])/3;
            cout << "Student ID: " << id[0] << id[1] << " average days in course is: " << avgDays << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram program) {
    for (int i=0; i < 5; i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == 2) {
            classRosterArray[i]->Print();
        }
    }
    cout << endl;
}

void Roster::remove(string id) {
    for (int i=0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            cout << "Student could not be found.";
        }
        else if (classRosterArray[i]->GetId() == "A3") {
            classRosterArray[i] = nullptr;
        }
    }
}

