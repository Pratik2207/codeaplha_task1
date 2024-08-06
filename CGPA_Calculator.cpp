#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Course {
public:
    string name;
    double grade;
    int credits;

    Course(string n, double g, int c) : name(n), grade(g), credits(c) {}
};

class Student {
public:
    string name;
    vector<Course> courses;

    Student(string n) : name(n) {}

    void addCourse(string courseName, double courseGrade, int courseCredits) {
        courses.push_back(Course(courseName, courseGrade, courseCredits));
    }

    double calculateCGPA() {
        double totalGradePoints = 0;
        int totalCredits = 0;
        for (const auto &course : courses) {
            totalGradePoints += course.grade * course.credits;
            totalCredits += course.credits;
        }
        return totalCredits == 0 ? 0 : totalGradePoints / totalCredits;
    }

    void displayGrades() {
        cout << "Grades for " << name << ":\n";
        cout << left << setw(20) << "Course" << setw(10) << "Grade" << setw(10) << "Credits" << "\n";
        for (const auto &course : courses) {
            cout << left << setw(20) << course.name << setw(10) << course.grade << setw(10) << course.credits << "\n";
        }
        cout << "CGPA: " << calculateCGPA() << "\n";
    }
};

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    vector<Student> students;

    for (int i = 0; i < numStudents; ++i) {
        string studentName;
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, studentName);
        Student student(studentName);

        int numCourses;
        cout << "Enter number of courses for " << studentName << ": ";
        cin >> numCourses;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        for (int j = 0; j < numCourses; ++j) {
            string courseName;
            double courseGrade;
            int courseCredits;

            cout << "Enter name of course " << j + 1 << ": ";
            getline(cin, courseName);
            cout << "Enter grade for " << courseName << ": ";
            cin >> courseGrade;
            cout << "Enter credits for " << courseName << ": ";
            cin >> courseCredits;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            student.addCourse(courseName, courseGrade, courseCredits);
        }

        students.push_back(student);
    }

    for (auto &student : students) {
        student.displayGrades();
        cout << "\n";
    }

    return 0;
}
