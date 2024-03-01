#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Class to represent a subject
class Subject {
private:
    string name;
    int creditHours;
    char grade;

public:
    // Constructor
    Subject(string n, int ch) : name(n), creditHours(ch), grade('F') {}

    // Getter and setter methods
    string getName() const {
        return name;
    }

    int getCreditHours() const {
        return creditHours;
    }

    char getGrade() const {
        return grade;
    }

    void setGrade(char g) {
        grade = g;
    }
};

// Class to represent a student
class Student {
private:
    string name;
    string className;
    vector<Subject> subjects;

public:
    // Constructor
    Student(string n, string cn) : name(n), className(cn) {}

    // Function to add a subject
    void addSubject(string subjectName, int creditHours) {
        Subject newSubject(subjectName, creditHours);
        subjects.push_back(newSubject);
    }

    // Function to input grades for all subjects
    void inputGrades() {
        cout << "Enter grades for each subject:" << endl;
        for (int i = 0; i < subjects.size(); ++i) {
            char grade;
            cout << "Grade for " << subjects[i].getName() << ": ";
            cin >> grade;
            subjects[i].setGrade(grade);
        }
    }

    // Function to calculate CGPA
    double calculateCGPA() const {
        double totalGradePoints = 0.0;
        int totalCreditHours = 0;
        for (const Subject& subject : subjects) {
            totalCreditHours += subject.getCreditHours();
            totalGradePoints += subject.getCreditHours() * gradeToPoint(subject.getGrade());
        }
        return totalGradePoints / totalCreditHours;
    }

    // Helper function to convert grade to point
    double gradeToPoint(char grade) const {
        switch (grade) {
            case 'A':
                return 5.0;
            case 'B':
                return 4.0;
            case 'C':
                return 3.0;
            case 'D':
                return 2.0;
            default:
                return 1.0;
        }
    }

    // Function to display student information
    void displayStudentInfo() const {
        cout << "Name: " << name << endl;
        cout << "Class: " << className << endl;
        cout << "Subjects and Grades:" << endl;
        for (const Subject& subject : subjects) {
            cout << subject.getName() << ": " << subject.getGrade() << endl;
        }
        cout << "CGPA: " << fixed << setprecision(2) << calculateCGPA() << endl;
    }
};

int main() {
    string name, className;
    int numSubjects;

    // Input student information
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter class name: ";
    getline(cin, className);
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    // Create student object
    Student student(name, className);

    // Input subject names and credit hours
    for (int i = 0; i < numSubjects; ++i) {
        string subjectName;
        int creditHours;
        cout << "Enter subject " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, subjectName);
        cout << "Enter credit hours for " << subjectName << ": ";
        cin >> creditHours;
        student.addSubject(subjectName, creditHours);
    }

    // Input grades for each subject
    student.inputGrades();

    // Display student information
    cout << "\nStudent Information:" << endl;
    student.displayStudentInfo();

    return 0;
}
