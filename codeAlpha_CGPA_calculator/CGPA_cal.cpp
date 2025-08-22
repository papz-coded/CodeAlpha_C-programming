#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Convert grade to grade point
int getGradePoint(string grade) {
    if (grade == "A+" || grade == "a+") return 10;
    else if (grade == "A" || grade == "a") return 9;
    else if (grade == "B+" || grade == "b+") return 8;
    else if (grade == "B" || grade == "b") return 7;
    else if (grade == "C+" || grade == "c+") return 6;
    else if (grade == "C" || grade == "c") return 5;
    else if (grade == "D" || grade == "d") return 4;
    else return 0; // F or invalid grade
}

int main() {
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    float totalCredits = 0, totalGradePoints = 0;
    string grade;
    float credit;

    cout << fixed << setprecision(2);

    for (int i = 1; i <= n; ++i) {
        cout << "\nCourse " << i << ":\n";
        cout << "Enter grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credit;

        int gradePoint = getGradePoint(grade);
        float coursePoints = gradePoint * credit;

        totalCredits += credit;
        totalGradePoints += coursePoints;

        cout << "Grade Point: " << gradePoint << endl;
        cout << "Grade Points for this course: " << coursePoints << endl;
    }

    if (totalCredits == 0) {
        cout << "\nInvalid total credits. Cannot calculate CGPA.\n";
    } else {
        float cgpa = totalGradePoints / totalCredits;
        cout << "\n------ Final Result ------\n";
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    return 0;
}

