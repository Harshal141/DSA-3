/*
Title: Write a menu driven C++ program to implement binary tree/binary search tree with n 
nodes. 
Problem Statement: A Dictionary stores keywords and its meanings. Provide facility for 
adding new keywords, deleting keywords, updating values of any entry. Provide facility to 
display whole data sorted in ascending/ Descending order. Also find how many maximum 
comparisons may require for finding any keyword. Use Binary Search Tree for 
implementation. 
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    Node* createNode(string keyword, string meaning) {
        Node* newNode = new Node();
        newNode->keyword = keyword;
        newNode->meaning = meaning;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* root, string keyword, string meaning) {
        if (root == nullptr) {
            root = createNode(keyword, meaning);
            return root;
        }

        if (keyword < root->keyword)
            root->left = insertNode(root->left, keyword, meaning);
        else if (keyword > root->keyword)
            root->right = insertNode(root->right, keyword, meaning);

        return root;
    }

    void insertKeyword() {
        string keyword, meaning;
        cout << "Enter keyword: ";
        cin >> keyword;
        cout << "Enter meaning: ";
        cin.ignore();
        getline(cin, meaning);

        root = insertNode(root, keyword, meaning);
        cout << "Keyword inserted successfully!" << endl;
    }

    Node* searchKeyword(Node* root, string keyword, int& comparisons) {
        if (root == nullptr || root->keyword == keyword)
            return root;

        comparisons++;
        if (keyword < root->keyword)
            return searchKeyword(root->left, keyword, comparisons);

        return searchKeyword(root->right, keyword, comparisons);
    }

    void searchAndDisplay() {
        string keyword;
        cout << "Enter keyword to search: ";
        cin >> keyword;

        int comparisons = 0;
        Node* result = searchKeyword(root, keyword, comparisons);

        if (result != nullptr) {
            cout << "Keyword: " << result->keyword << endl;
            cout << "Meaning: " << result->meaning << endl;
            cout << "Comparisons required: " << comparisons << endl;
        } else {
            cout << "Keyword not found!" << endl;
        }
    }

    Node* findMinimum(Node* root) {
        if (root->left == nullptr)
            return root;
        return findMinimum(root->left);
    }

    Node* deleteKeyword(Node* root, string keyword) {
        if (root == nullptr)
            return root;

        if (keyword < root->keyword)
            root->left = deleteKeyword(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteKeyword(root->right, keyword);
        else {
            // Case 1: No child or one child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Two children
            Node* temp = findMinimum(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteKeyword(root->right, temp->keyword);
        }

        return root;
    }

    void deleteAndDisplay() {
        string keyword;
        cout << "Enter keyword to delete: ";
        cin >> keyword;

        root = deleteKeyword(root, keyword);
        cout << "Keyword deleted successfully!" << endl;
    }

    void displayAscending(Node* root) {
        if (root == nullptr)
            return;

        displayAscending(root->left);
        cout << "Keyword: " << root->keyword << endl;
        cout << "Meaning: " << root->meaning << endl;
        cout << "----------------------" << endl;
        displayAscending(root->right);
    }

    void displayDescending(Node* root) {
        if (root == nullptr)
            return;

        displayDescending(root->right);
        cout << "Keyword: " << root->keyword << endl;
        cout << "Meaning: " << root->meaning << endl;
        cout << "----------------------" << endl;
        displayDescending(root->left);
    }

    void displayData() {
        cout << "Display data in:" << endl;
        cout << "1. Ascending order" << endl;
        cout << "2. Descending order" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayAscending(root);
                break;
            case 2:
                displayDescending(root);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    void updateKeyword() {
        string keyword, newMeaning;
        cout << "Enter keyword to update: ";
        cin >> keyword;

        int comparisons = 0;
        Node* result = searchKeyword(root, keyword, comparisons);

        if (result != nullptr) {
            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, newMeaning);
            result->meaning = newMeaning;
            cout << "Keyword updated successfully!" << endl;
        } else {
            cout << "Keyword not found!" << endl;
        }
    }
};

int main() {
    BST dictionary;
    int choice;

    do {
        cout << "\n----- Dictionary Menu -----";
        cout << "\n1. Add new keyword";
        cout << "\n2. Search keyword and display meaning";
        cout << "\n3. Delete keyword";
        cout << "\n4. Display data";
        cout << "\n5. Update keyword meaning";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dictionary.insertKeyword();
                break;
            case 2:
                dictionary.searchAndDisplay();
                break;
            case 3:
                dictionary.deleteAndDisplay();
                break;
            case 4:
                dictionary.displayData();
                break;
            case 5:
                dictionary.updateKeyword();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
