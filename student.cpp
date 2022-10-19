//
//  student.cpp
//
//  Created by Matthew Pourroy on 10/9/22.
//
#include "student.h"

using namespace std;

//No arg constructor
Student::Student() {
    this->id = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) {
        daysArr[i] = 0;
    }
    this->program = DegreeProgram::SOFTWARE;
}

//Parameterized constructor
Student::Student(string id, string firstName, string lastName, string email, int age, int daysArr[], DegreeProgram program) {
    setId(id);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    for (int i = 0; i < 3; i++) {
        daysArr[i] = 0;
    }
    setDegreeProgram(program);
}

//Destructor
Student::~Student() {}

//Getter function definitions
string Student::GetId() const {
    return this->id;
}

string Student::GetFirstName() const {
    return this->firstName;
}

string Student::GetLastName() const {
    return this->lastName;
}

string Student::GetEmail() const {
    return this->email;
}

int Student::GetAge() const {
    return this->age;
}

int* Student::GetDaysArr() const {
    return this->daysArr;
}

DegreeProgram Student::GetDegreeProgram() {
    return this->program;
}

//Setter function definitions
void Student::setId(string id) {
    this->id = id;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysArr(int daysArr[]) {
    this->daysArr = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daysArr[i] = daysArr[i];
    }
}

void Student::setDegreeProgram(DegreeProgram program) {
    this->program = program;
}

void Student::Print() {
    cout << GetId() << '\t';
    cout << GetFirstName() << '\t';
    cout << GetLastName() << '\t';
    cout << GetEmail() << '\t';
    cout << GetAge() << '\t';
    cout << daysArr[0] << '\t';
    cout << daysArr[1] << '\t';
    cout << daysArr[2] << '\t';
    if (this->GetDegreeProgram() == 0) {
        cout << "SECURITY";
    }
    else if (this->GetDegreeProgram() == 1) {
        cout << "NETWORK";
    }
    else {
        cout << "SOFTWARE";
    }
}


