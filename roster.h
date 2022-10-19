//
//  roster.h
//
//  Created by Matthew Pourroy on 10/9/22.
//

#ifndef roster_h
#define roster_h
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

#endif /* roster_h */

class Roster {
public:
    ~Roster();
    
    void add(string id, string firstName, string lastName, string email, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram program);
    void parse(string studentData);
    void remove(string id);
    void printAll();
    void printAverageDaysInCourse(string id);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram program);
    
    int lastIdx = -1;
    Student* classRosterArray[5];
};

