/*
Title: Write a menu driven C++ program to implement Height Balanced Binary Tree (AVL 
Tree) 
Problem Statement: A Dictionary stores keywords & its meanings. Provide facility for 
1. Add new keyword 
2. Delete keyword 
3. Update values of any entry. 
4. Sort data in Ascending & Descending order. 
5. Find how many maximum comparisons may require for finding any keyword. 
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;
};
class AVLTree {
private:
    Node* root;
public:
    AVLTree() {
        root = nullptr;
    }
    int getHeight(Node* node) {
        if (node == nullptr)
            return -1;
        return node->height;
    }
    void updateHeight(Node* node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + max(leftHeight, rightHeight);
    }
    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }
    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }
    Node* balance(Node* node) {
        if (node == nullptr)
            return nullptr;
        updateHeight(node);
        int balanceFactor = getHeight(node->left) - getHeight(node->right);
        if (balanceFactor > 1 && getHeight(node->left->left) >= getHeight(node->left->right))
            return rotateRight(node);
        if (balanceFactor > 1 && getHeight(node->left->left) < getHeight(node->left->right)) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && getHeight(node->right->right) >= getHeight(node->right->left))
            return rotateLeft(node);
        if (balanceFactor < -1 && getHeight(node->right->right) < getHeight(node->right->left)) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    Node* insert(Node* node, const string& keyword, const string& meaning) {
        if (node == nullptr) {
            node = new Node;
            node->keyword = keyword;
            node->meaning = meaning;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 0;
            return node;
        }
        if (keyword < node->keyword)
            node->left = insert(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insert(node->right, keyword, meaning);
        else {
            cout << "Keyword already exists!" << endl;
            return node;
        }
        return balance(node);
    }
    Node* remove(Node* node, const string& keyword) {
        if (node == nullptr) {
            cout << "Keyword not found!" << endl;
            return nullptr;
        }
        if (keyword < node->keyword)
            node->left = remove(node->left, keyword);
        else if (keyword > node->keyword)
            node->right = remove(node->right, keyword);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* minRightNode = findMinNode(node->right);
                node->keyword = minRightNode->keyword;
                node->meaning = minRightNode->meaning;
                node->right = remove(node->right, minRightNode->keyword);
            }
        }
        return balance(node);
    }
    Node* findMinNode(Node* node) {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
    Node* findMaxNode(Node* node) {
        if (node == nullptr)
            return nullptr;
        while (node->right != nullptr)
            node = node->right;
        return node;
    }
    void updateMeaning(Node* node, const string& keyword, const string& newMeaning) {
        if (node == nullptr) {
            cout << "Keyword not found!" << endl;
            return;
        }
        if (keyword < node->keyword)
            updateMeaning(node->left, keyword, newMeaning);
        else if (keyword > node->keyword)
            updateMeaning(node->right, keyword, newMeaning);
        else {
            node->meaning = newMeaning;
            cout << "Meaning updated successfully!" << endl;
        }
    }
    void displayAscending(Node* node) {
        if (node != nullptr) {
            displayAscending(node->left);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayAscending(node->right);
        }
    }
    void displayDescending(Node* node) {
        if (node != nullptr) {
            displayDescending(node->right);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayDescending(node->left);
        }
    }
    Node* search(Node* node, const string& keyword, int& comparisons) {
        if (node == nullptr)
            return nullptr;
        comparisons++;
        if (keyword < node->keyword)
            return search(node->left, keyword, comparisons);
        else if (keyword > node->keyword)
            return search(node->right, keyword, comparisons);
        else
            return node;
    }
    int getMaxComparisons(const string& keyword) {
        int comparisons = 0;
        search(root, keyword, comparisons);
        return comparisons;
    }
    void addKeyword() {
        string keyword, meaning;
        cout << "Enter the keyword: ";
        cin >> keyword;
        cin.ignore();
        cout << "Enter the meaning: ";
        getline(cin, meaning);
        root = insert(root, keyword, meaning);
        cout << "Keyword added successfully!" << endl;
    }
    void deleteKeyword() {
        string keyword;
        cout << "Enter the keyword to delete: ";
        cin >> keyword;
        root = remove(root, keyword);
    }
    void updateKeyword() {
        string keyword, newMeaning;
        cout << "Enter the keyword to update: ";
        cin >> keyword;
        cin.ignore();
        cout << "Enter the new meaning: ";
        getline(cin, newMeaning);
        updateMeaning(root, keyword, newMeaning);
    }
    void displayAscendingOrder() {
        if (root == nullptr) {
            cout << "No data found!" << endl;
            return;
        }
        cout << "Keywords and meanings in ascending order:" << endl;
        displayAscending(root);
    }
    void displayDescendingOrder() {
        if (root == nullptr) {
            cout << "No data found!" << endl;
            return;
        }
        cout << "Keywords and meanings in descending order:" << endl;
        displayDescending(root);
    }
    void searchKeyword() {
        string keyword;
        cout << "Enter the keyword to search: ";
        cin >> keyword;
        int comparisons = 0;
        Node* result = search(root, keyword, comparisons);
        if (result != nullptr)
            cout << "Meaning: " << result->meaning << endl;
        else
            cout << "Keyword not found!" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }
};
int main() {
    AVLTree dictionary;
    int choice;
    do {
        cout << "\nDictionary Management System" << endl;
        cout << "1. Add Keyword" << endl;
        cout << "2. Delete Keyword" << endl;
        cout << "3. Update Meaning" << endl;
        cout << "4. Display in Ascending Order" << endl;
        cout << "5. Display in Descending Order" << endl;
        cout << "6. Search Keyword" << endl;
        cout << "7. Calculate Maximum Comparisons" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                dictionary.addKeyword();
                break;
            case 2:
                dictionary.deleteKeyword();
                break;
            case 3:
                dictionary.updateKeyword();
                break;
            case 4:
                dictionary.displayAscendingOrder();
                break;
            case 5:
                dictionary.displayDescendingOrder();
                break;
            case 6:
                dictionary.searchKeyword();
                break;
            case 7:{
                string keyword;
                cout << "Enter the keyword: ";
                cin >> keyword;
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons(keyword) << endl;
                break;
            }
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 8);
    return 0;
}


