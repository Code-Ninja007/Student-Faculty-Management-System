#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Student {
    int id, year, attendance;
    string name, course;
    float cgpa, fees, dueFee;
    bool exists;

    Student() : id(0), name(""), course(""), year(0), attendance(0), cgpa(0.0), fees(0.0), dueFee(0.0), exists(false) {}

    void input() {
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Course: "; getline(cin, course);
        cout << "Enter Year: "; cin >> year;
        cout << "Enter CGPA: "; cin >> cgpa;
        cout << "Enter Attendance (%): "; cin >> attendance;
        cout << "Enter Total Fees: "; cin >> fees;
        cout << "Enter Due Fees: "; cin >> dueFee;
        exists = true;
        saveToCSV();
    }

    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nCourse: " << course << "\nYear: " << year
             << "\nCGPA: " << cgpa << "\nAttendance: " << attendance << "%\nTotal Fees: " << fees << "\nDue Fees: " << dueFee << "\n";
    }

    void saveToCSV() {
        ofstream file("students.csv", ios::app);
        if (file.is_open()) {
            file << id << "," << name << "," << course << "," << year << ","
                 << cgpa << "," << attendance << "," << fees << "," << dueFee << "\n";
            file.close();
        }
    }
};

struct Faculty {
    int id, attendance;
    string name, department, salarySlip, allotedClasses;
    bool exists;

    Faculty() : id(0), name(""), department(""), attendance(0), salarySlip(""), allotedClasses(""), exists(false) {}

    void input() {
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Department: "; getline(cin, department);
        cout << "Enter Attendance (%): "; cin >> attendance; cin.ignore();
        cout << "Enter Salary Slip: "; getline(cin, salarySlip);
        cout << "Enter Alloted Classes: "; getline(cin, allotedClasses);
        exists = true;
        saveToCSV();
    }

    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nDepartment: " << department
             << "\nAttendance: " << attendance << "%\nSalary Slip: " << salarySlip
             << "\nAlloted Classes: " << allotedClasses << "\n";
    }

    void saveToCSV() {
        ofstream file("faculties.csv", ios::app);
        if (file.is_open()) {
            file << id << "," << name << "," << department << "," << attendance << ","
                 << salarySlip << "," << allotedClasses << "\n";
            file.close();
        }
    }
};

struct Course {
    int code, duration;
    string title;
    bool exists;

    Course() : code(0), title(""), duration(0), exists(false) {}

    void input() {
        cout << "Enter Course Code: "; cin >> code;
        cout << "Enter Title: "; cin.ignore(); getline(cin, title);
        cout << "Enter Duration (months): "; cin >> duration;
        exists = true;
        saveToCSV();
    }

    void display() {
        cout << "Course Code: " << code << "\nTitle: " << title << "\nDuration: " << duration << " months\n";
    }

    void saveToCSV() {
        ofstream file("courses.csv", ios::app);
        if (file.is_open()) {
            file << code << "," << title << "," << duration << "\n";
            file.close();
        }
    }
};

Student students[10];
Faculty faculties[10];
Course courses[10];

void studentMenu();
void facultyMenu();
void courseMenu();

int main() {
    int choice;
    while (true) {
        system("CLS");
        cout << "====== KIT ERP SYSTEM ======\n";
        cout << "1. Student Management\n2. Faculty Management\n3. Course Management\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: studentMenu(); break;
            case 2: facultyMenu(); break;
            case 3: courseMenu(); break;
            case 4: exit(0);
            default: cout << "Invalid choice.\n"; getch(); break;
        }
    }
    return 0;
}

void studentMenu() {
    int ch, id;
    bool found = false;
    while (true) {
        system("CLS");
        cout << "----- Student Menu -----\n";
        cout << "1. Add Student\n2. View Students\n3. Modify Student\n4. Delete Student\n5. Back\n";
        cout << "Enter choice: "; cin >> ch;
        switch (ch) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    if (!students[i].exists) {
                        students[i].input();
                        cout << "Student added.\n";
                        break;
                    }
                }
                break;
            case 2:
                for (Student& s : students) {
                    if (s.exists) {
                        s.display();
                        cout << "----------------------\n";
                    }
                }
                break;
            case 3:
                cout << "Enter Student ID to modify: ";
                cin >> id;
                found = false;
                for (Student& s : students) {
                    if (s.exists && s.id == id) {
                        s.input();
                        cout << "Modified.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            case 4:
                cout << "Enter Student ID to delete: ";
                cin >> id;
                found = false;
                for (Student& s : students) {
                    if (s.exists && s.id == id) {
                        s = Student();
                        cout << "Deleted.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            case 5: return;
            default: cout << "Invalid.\n"; break;
        }
        getch();
    }
}

void facultyMenu() {
    int ch, id;
    bool found = false;
    while (true) {
        system("CLS");
        cout << "----- Faculty Menu -----\n";
        cout << "1. Add Faculty\n2. View Faculties\n3. Modify Faculty\n4. Delete Faculty\n5. Back\n";
        cout << "Enter choice: "; cin >> ch;
        switch (ch) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    if (!faculties[i].exists) {
                        faculties[i].input();
                        cout << "Faculty added.\n";
                        break;
                    }
                }
                break;
            case 2:
                for (Faculty& f : faculties) {
                    if (f.exists) {
                        f.display();
                        cout << "----------------------\n";
                    }
                }
                break;
            case 3:
                cout << "Enter Faculty ID to modify: ";
                cin >> id;
                found = false;
                for (Faculty& f : faculties) {
                    if (f.exists && f.id == id) {
                        f.input();
                        cout << "Modified.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Faculty not found.\n";
                break;
            case 4:
                cout << "Enter Faculty ID to delete: ";
                cin >> id;
                found = false;
                for (Faculty& f : faculties) {
                    if (f.exists && f.id == id) {
                        f = Faculty();
                        cout << "Deleted.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Faculty not found.\n";
                break;
            case 5: return;
            default: cout << "Invalid.\n"; break;
        }
        getch();
    }
}

void courseMenu() {
    int ch, code;
    bool found = false;
    while (true) {
        system("CLS");
        cout << "----- Course Menu -----\n";
        cout << "1. Add Course\n2. View Courses\n3. Modify Course\n4. Delete Course\n5. Back\n";
        cout << "Enter choice: "; cin >> ch;
        switch (ch) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    if (!courses[i].exists) {
                        courses[i].input();
                        cout << "Course added.\n";
                        break;
                    }
                }
                break;
            case 2:
                for (Course& c : courses) {
                    if (c.exists) {
                        c.display();
                        cout << "----------------------\n";
                    }
                }
                break;
            case 3:
                cout << "Enter Course Code to modify: ";
                cin >> code;
                found = false;
                for (Course& c : courses) {
                    if (c.exists && c.code == code) {
                        c.input();
                        cout << "Modified.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Course not found.\n";
                break;
            case 4:
                cout << "Enter Course Code to delete: ";
                cin >> code;
                found = false;
                for (Course& c : courses) {
                    if (c.exists && c.code == code) {
                        c = Course();
                        cout << "Deleted.\n"; found = true; break;
                    }
                }
                if (!found) cout << "Course not found.\n";
                break;
            case 5: return;
            default: cout << "Invalid.\n"; break;
        }
        getch();
    }
}