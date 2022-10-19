//
//  student.h
//
//  Created by Matthew Pourroy on 10/9/22.
//

#include <string>
#include <cstring>
#ifndef student_h
#define student_h
#include "degree.h"
#include <iostream>

#endif /* student_h */
using namespace std;

class Student {
public:
    //Default Constructor
    Student();
    
    //Parameterized Constructor
    Student(string id, string firstName, string lastName, string email, int age, int daysArr[], DegreeProgram program);
    
    //Destructor
    ~Student();
    
    //Setter functions
    void setId(string id);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysArr(int daysArr[]);
    void setDegreeProgram(DegreeProgram program);
    
    
    void Print();
    
    //Getter functions
    string GetId() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmail() const;
    int GetAge() const;
    int* GetDaysArr() const;
    DegreeProgram GetDegreeProgram();
    
    //Number of days in the days array
    const static int numDays = 3;
    
private:
    string id;
    string firstName;
    string lastName;
    string email;
    int age;
    int* daysArr;
    DegreeProgram program;
};

