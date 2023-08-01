#include <iostream>
#include <string>

using std::string;

string letterGradeToNumber433(string letter) {
    if (letter == "A+" || letter == "a+") {
        return "433";
    } else if (letter == "A" || letter == "a") {
        return "400";
    } else if (letter == "A-" || letter == "a-") {
        return "367";
    } else if (letter == "B+" || letter == "b+") {
        return "333";
    } else if (letter == "B" || letter == "b") {
        return "300";
    } else if (letter == "B-" || letter == "b-") {
        return "267";
    } else if (letter == "C+" || letter == "c+") {
        return "233";
    } else if (letter == "C" || letter == "c") {
        return "200";
    } else if (letter == "C-" || letter == "c-") {
        return "167";
    } else if (letter == "D" || letter == "d") {
        return "100";
    } else if (letter == "F" || letter == "f") {
        return "0";
    } else {
        return "invalid";
    }
}

string letterGradeToNumber400(string letter) {
    if (letter == "A+" || letter == "a+") {
        return "400";
    } else if (letter == "A" || letter == "a") {
        return "400";
    } else if (letter == "A-" || letter == "a-") {
        return "370";
    } else if (letter == "B+" || letter == "b+") {
        return "330";
    } else if (letter == "B" || letter == "b") {
        return "300";
    } else if (letter == "B-" || letter == "b-") {
        return "270";
    } else if (letter == "C+" || letter == "c+") {
        return "230";
    } else if (letter == "C" || letter == "c") {
        return "200";
    } else if (letter == "C-" || letter == "c-") {
        return "170";
    } else if (letter == "D+" || letter == "d+") {
        return "130";
    }
    else if (letter == "D" || letter == "d") {
        return "100";
    } else if (letter == "F" || letter == "f") {
        return "0";
    } else {
        return "invalid";
    }
}