#include <iostream>
#include <iomanip>
#include <string>

#include "string_math_library.hpp"
#include "letter_grades.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main() {
    // ask user how many courses they want to enter
    int numCourses;
    cout << "How many courses do you want to enter? " << endl;
    cin >> numCourses;

    // create array of grades
    string gradesArr[numCourses];

    // create array of credits
    string creditsArr[numCourses];

    // create array of course names
    string courseNamesArr[numCourses];
    
    string totalCredits = "0";
    string totalGradePoints = "0";
    string gpaScale;

    cout << "\nAre you operating on a 4.33 scale or a 4.0 scale? (Enter 4.33/4.0)" << endl;
    cin >> gpaScale;
    while (gpaScale != "4.33" && gpaScale != "4.0") {
        cout << "Invalid GPA scale. Please try again." << endl;
        cin >> gpaScale;
    }
    cout << endl;


    // loop through and take user inputs
    for (int i = 0; i < numCourses; i++) {
        string currGrade;
        string currCredit; 
        string currName;
        cout << "";
        if (i == 0) {
            cout << "Enter the course name: ";
        } else {
            cout << "Enter next course name: ";
        }
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, currName);
        courseNamesArr[i] = currName;
        cout << "Enter your letter grade for course " << currName << ": ";
        cin >> currGrade;

        while (letterGradeToNumber433(currGrade) == "invalid") {
            cout << "Invalid letter grade. Please try again." << endl;
            cin >> currGrade;
        }

        cout << "Enter the number of credits for course " << currName << ": ";
        cin >> currCredit;
        while (currCredit < "1" || currCredit > "4") {
            cout << "Invalid number of credits. Please try again." << endl;
            cin >> currCredit;
        }
        
        // add current course to arrays
        gradesArr[i] = currGrade;
        creditsArr[i] = currCredit;

        // calculate grade points for current course
        if (gpaScale == "4.0") {
            currGrade = letterGradeToNumber400(currGrade);
        } else {
            currGrade = letterGradeToNumber433(currGrade);
        }
        string currGradePoints = vix::multiply_strings(currGrade, currCredit);
        totalGradePoints = vix::add_strings(totalGradePoints, currGradePoints); // add grade points to total grade points

        // add credits to total credits
        totalCredits = vix::add_strings(totalCredits, currCredit);

        cout << endl;
    }

    // caculate total gpa
    float gpa = (stoi (totalGradePoints) / stoi (totalCredits)) / 100;
    cout << "-------------------------------------------------" << endl;
    cout << "Your Overall GPA is " <<std::fixed <<std::setprecision(2) << gpa << endl << endl;

    cout << "Here is a list of your courses: " << endl << endl;


    // print out course names, grades, and credits
    for (int i = 0; i < numCourses; i++) {
        char letterGrade = toupper(gradesArr[i][0]);
        cout << courseNamesArr[i] << ": " << letterGrade << gradesArr[i][1] << " (" << creditsArr[i] << " credits)" << endl;
    }

    cout << endl;
    return 0;
}