//
//  main.cpp
//  Created by Matthew Pourroy on 10/9/22.
//
#include <iostream>
#include "roster.h"
#include <iomanip>
#include <string>
#include "student.h"
#include "roster.h"

using namespace std;

int main() {
    //Student Data Table
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Matthew,Pourroy,pourroy.matt@gmail.com,25,20,25,30,SOFTWARE"};
    
    //Prints out my details
    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001523178" << endl;
    cout << "Name: Matthew Pourroy" << endl;
    
    //Displays all students
    Roster classRoster;
    
    cout << "Displaying all students:" << endl;
    for (int i=0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
    
    classRoster.printAll();

    //Displays invalid emails
    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    //Displays average days it takes a student to complete a course
    cout << "Average days in course: " << endl;
    for (int i=0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetId());
    }

    //Displays students in software degree program
    cout << "Showing students in degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    //Removes student id A3 and prints new array
    cout << "Removing A3" << endl;
    classRoster.remove("A3");
    
    
    classRoster.printAll();

    //Removes student id A3 again
    cout << "Removing A3 again" << endl;
    classRoster.remove("A3");
    
    return 0;
}
