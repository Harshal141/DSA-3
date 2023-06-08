/*
Title: Write Python/C++ program to implement quadratic probing collision handling 
techniques in hashing. 
Problem Statement: Consider below insertion sequence 
Data: 89,18,49,58,9 
Size of Hash Table: 10 Hash Function: (key % size) 
1. Quick Insert (collision handling using Quadratic probing) 
2. Delete 
3. Lookup/ Search
*/

#include <iostream>
using namespace std;

class HashTable {
private:
    int size;
    int* data;
    bool* isOccupied;

public:
    HashTable(int tableSize) {
        size = tableSize;
        data = new int[size];
        isOccupied = new bool[size];
        for (int i = 0; i < size; i++) {
            isOccupied[i] = false;
        }
    }

    ~HashTable() {
        delete[] data;
        delete[] isOccupied;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int value) {
        int key = value;
        int index = hashFunction(key);

        if (isOccupied[index]) {
            int i = 1;
            while (true) {
                int new_index = (index + i * i) % size;
                if (!isOccupied[new_index]) {
                    index = new_index;
                    break;
                }
                i++;
            }
        }

        data[index] = value;
        isOccupied[index] = true;
    }

    void remove(int value) {
        int key = value;
        int index = hashFunction(key);

        if (!isOccupied[index]) {
            cout << "Value " << value << " not found in the hash table." << endl;
            return;
        }

        int i = 0;
        while (true) {
            if (data[index] == value) {
                isOccupied[index] = false;
                cout << "Value " << value << " removed from the hash table." << endl;
                return;
            }
            i++;
            index = (index + i * i) % size;
            if (!isOccupied[index]) {
                cout << "Value " << value << " not found in the hash table." << endl;
                return;
            }
        }
    }

    void search(int value) {
        int key = value;
        int index = hashFunction(key);

        if (!isOccupied[index]) {
            cout << "Value " << value << " not found in the hash table." << endl;
            return;
        }

        int i = 0;
        while (true) {
            if (data[index] == value) {
                cout << "Value " << value << " found in the hash table." << endl;
                return;
            }
            i++;
            index = (index + i * i) % size;
            if (!isOccupied[index]) {
                cout << "Value " << value << " not found in the hash table." << endl;
                return;
            }
        }
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (isOccupied[i]) {
                cout << "Index " << i << ": " << data[i] << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable(10);

    int data[] = {89, 18, 49, 58, 9};
    int numData = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < numData; i++) {
        hashTable.insert(data[i]);
    }

    cout << "After inserting data:" << endl;
    hashTable.display();

    cout << endl;

    int valueToDelete = 49;
    hashTable.remove(valueToDelete);

    cout << endl;

    cout << "After removing value " << valueToDelete << ":" << endl;
    hashTable.display();

    cout << endl;

    int valueToSearch = 18;
    hashTable.search(valueToSearch);

    return 0;
}
