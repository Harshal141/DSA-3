/*
Title: Write Python/C++ program to implement separate chaining (Open Hashing/Closed 
Addressing) collision handling techniques in hashing. 
Problem Statement: Consider the student database of N students and their marks. Make use 
of a hash table implementation to quickly insert and lookup student’s PNR(key) and marks. 
Data: {(3200, 72), (3201, 56), (3204, 78), (3209, 62), (3216, 55), (3225, 81), (3236, 71), (3249, 
69), (3264, 66), (3281, 88) } Size of Hash Table: 10 Hash Function: (key % size)
*/

#include <iostream>
#include <list>
using namespace std;

struct Student {
    int pnr;
    int marks;
};

class HashTable {
private:
    int size;
    list<Student>* data;

public:
    HashTable(int tableSize) {
        size = tableSize;
        data = new list<Student>[size];
    }

    ~HashTable() {
        delete[] data;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(Student student) {
        int key = student.pnr;
        int index = hashFunction(key);
        data[index].push_back(student);
    }

    void remove(int pnr) {
        int key = pnr;
        int index = hashFunction(key);

        for (auto it = data[index].begin(); it != data[index].end(); ++it) {
            if (it->pnr == pnr) {
                data[index].erase(it);
                cout << "Student with PNR " << pnr << " removed from the hash table." << endl;
                return;
            }
        }

        cout << "Student with PNR " << pnr << " not found in the hash table." << endl;
    }

    void search(int pnr) {
        int key = pnr;
        int index = hashFunction(key);

        for (auto it = data[index].begin(); it != data[index].end(); ++it) {
            if (it->pnr == pnr) {
                cout << "Student with PNR " << pnr << " found. Marks: " << it->marks << endl;
                return;
            }
        }

        cout << "Student with PNR " << pnr << " not found in the hash table." << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (data[i].empty()) {
                cout << "Empty" << endl;
            } else {
                for (auto it = data[i].begin(); it != data[i].end(); ++it) {
                    cout << "(PNR = " << it->pnr << ", Marks = " << it->marks << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable(10);

    Student students[] = {
        {3200, 72},
        {3201, 56},
        {3204, 78},
        {3209, 62},
        {3216, 55},
        {3225, 81},
        {3236, 71},
        {3249, 69},
        {3264, 66},
        {3281, 88}
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < numStudents; i++) {
        hashTable.insert(students[i]);
    }

    cout << "After inserting student data:" << endl;
    hashTable.display();

    cout << endl;

    int pnrToDelete = 3225;
    hashTable.remove(pnrToDelete);

    cout << endl;

    cout << "After removing student with PNR " << pnrToDelete << ":" << endl;
    hashTable.display();

    cout << endl;

    int pnrToSearch = 3204;
    hashTable.search(pnrToSearch);

    return 0;
}
