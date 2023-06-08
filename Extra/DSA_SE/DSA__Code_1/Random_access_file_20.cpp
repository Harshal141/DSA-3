/*
Title: Write a menu driven C++ program to implement Random Access File Org 
 
Problem Statement: Department maintains student information. The file contains rollno, 
name, division and address. Allow user to add, delete, insert and search information of student.

*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    char division;
    char address[100];
};

// Function to add a new student record
void addStudentRecord(fstream& file) {
    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(student.name, 50);

    cout << "Enter Division: ";
    cin >> student.division;

    cin.ignore();
    cout << "Enter Address: ";
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    cout << "Student record added successfully.\n";
}

// Function to delete a student record based on roll number
void deleteStudentRecord(fstream& file) {
    int rollNo;
    cout << "Enter the Roll No to delete: ";
    cin >> rollNo;

    file.seekg(0, ios::beg);
    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            found = true;
            break;
        }
    }

    if (found) {
        file.seekp(-sizeof(Student), ios::cur);
        Student deletedStudent;
        deletedStudent.rollNo = -1;
        file.write(reinterpret_cast<char*>(&deletedStudent), sizeof(Student));
        cout << "Student record deleted successfully.\n";
    } else {
        cout << "Student record not found.\n";
    }
}

// Function to insert a new student record at a given position
void insertStudentRecord(fstream& file) {
    int pos;
    cout << "Enter the position to insert (1-based index): ";
    cin >> pos;

    if (pos <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    file.seekg(0, ios::end);
    int endPos = file.tellg();
    int recordSize = sizeof(Student);

    if (pos * recordSize > endPos) {
        cout << "Invalid position.\n";
        return;
    }

    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(student.name, 50);

    cout << "Enter Division: ";
    cin >> student.division;

    cin.ignore();
    cout << "Enter Address: ";
    cin.getline(student.address, 100);

    int insertPos = (pos - 1) * recordSize;
    file.seekp(insertPos);

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    cout << "Student record inserted successfully.\n";
}

// Function to search for a student record based on roll number
void searchStudentRecord(fstream& file) {
    int rollNo;
    cout << "Enter the Roll No to search: ";
    cin >> rollNo;

    file.seekg(0, ios::beg);
    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Student record found:\n";
        cout << "Roll No: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "Division: " << student.division << endl;
        cout << "Address: " << student.address << endl;
    } else {
        cout << "Student record not found.\n";
    }
}

int main() {
    fstream file("students.dat", ios::binary | ios::in | ios::out | ios::ate);

    if (!file) {
        cout << "Error opening file.";
        return 0;
    }

    int choice;
    do {
        cout << "\n------ Student Information Menu ------\n";
        cout << "1. Add Student Record\n";
        cout << "2. Delete Student Record\n";
        cout << "3. Insert Student Record\n";
        cout << "4. Search Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord(file);
                break;
            case 2:
                deleteStudentRecord(file);
                break;
            case 3:
                insertStudentRecord(file);
                break;
            case 4:
                searchStudentRecord(file);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    file.close();

    return 0;
}
