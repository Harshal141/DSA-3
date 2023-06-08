/*
Title: Write a menu driven C++ program to implement Sequential Access File Org 
Problem Statement: 
Department maintains student information. The file contains rollno, name, division and 
address. Allow user to add, delete, insert and search information of student.
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

void addStudentRecord() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore(); // Ignore the newline character
    cout << "Enter Name: ";
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore(); // Ignore the newline character
    cout << "Enter Address: ";
    cin.getline(student.address, 100);

    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    outFile.close();

    cout << "Student record added successfully." << endl;
}

void deleteStudentRecord() {
    ifstream inFile("students.txt", ios::binary);

    if (!inFile) {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt", ios::binary);

    if (!tempFile) {
        cout << "Error opening file." << endl;
        inFile.close();
        return;
    }

    int rollNo;
    cout << "Enter Roll No to delete: ";
    cin >> rollNo;

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo != rollNo) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "Student record deleted successfully." << endl;
    } else {
        cout << "Student record not found." << endl;
    }
}

void insertStudentRecord() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file." << endl;
        return;
    }

    int position;
    cout << "Enter the position to insert (1-based index): ";
    cin >> position;

    if (position <= 0) {
        cout << "Invalid position." << endl;
        outFile.close();
        return;
    }

    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore(); // Ignore the newline character
    cout << "Enter Name: ";
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore(); // Ignore the newline character
    cout << "Enter Address: ";
    cin.getline(student.address, 100);

    outFile.seekp((position - 1) * sizeof(Student));
    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    outFile.close();

    cout << "Student record inserted successfully." << endl;
}

void searchStudentRecord() {
    ifstream inFile("students.txt", ios::binary);

    if (!inFile) {
        cout << "Error opening file." << endl;
        return;
    }

    int rollNo;
    cout << "Enter Roll No to search: ";
    cin >> rollNo;

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            cout << "Student Record:" << endl;
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n------ Student Information Menu ------" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Insert Student Record" << endl;
        cout << "4. Search Student Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                deleteStudentRecord();
                break;
            case 3:
                insertStudentRecord();
                break;
            case 4:
                searchStudentRecord();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
