
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

// Load student records
void loadStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);

        students.push_back(s);
    }

    file.close();
}

// Save student records
void saveStudents() {
    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++) {
        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].course << endl;
    }

    file.close();
}

// Add student
void addStudent() {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == s.id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    students.push_back(s);
    saveStudents();

    cout << "Student Added Successfully!\n";
}

// Display students
void displayStudents() {
    if (students.empty()) {
        cout << "No Records Found!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\nStudent ID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nAge: " << students[i].age;
        cout << "\nCourse: " << students[i].course;
        cout << "\n----------------------\n";
    }
}

// Search student
void searchStudent() {
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            return;
        }
    }

    cout << "Student Not Found!\n";
}

// Delete student
void deleteStudent() {
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveStudents();

            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

// Main function
int main() {
    loadStudents();

    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}

