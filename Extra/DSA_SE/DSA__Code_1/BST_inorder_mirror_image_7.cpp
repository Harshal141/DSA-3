/*
Title: Write a menu driven C++ program to implement binary tree/binary search tree with n 
nodes. 
do following operation 
1. Insert a node in a BST 
2. Find the height of a tree. 
3. Create clone of a tree and then erase all nodes in a original tree. 
4. create a Mirror image of a tree. 
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;

public:
    BST() {
        root = nullptr;
    }

    TreeNode* createNode(int value) {
        TreeNode* newNode = new TreeNode();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return createNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    int findHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }

        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    TreeNode* cloneTree(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* clone = createNode(node->data);
        clone->left = cloneTree(node->left);
        clone->right = cloneTree(node->right);

        return clone;
    }

    void eraseTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        eraseTree(node->left);
        eraseTree(node->right);
        delete node;
    }

    TreeNode* mirrorImage(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* mirror = createNode(node->data);
        mirror->left = mirrorImage(node->right);
        mirror->right = mirrorImage(node->left);

        return mirror;
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node inserted successfully." << endl;
    }

    void findTreeHeight() {
        int height = findHeight(root);
        cout << "Height of the tree: " << height << endl;
    }

    void createCloneAndErase() {
        TreeNode* clone = cloneTree(root);
        cout << "Clone of the tree created successfully." << endl;

        eraseTree(root);
        root = nullptr;

        cout << "All nodes erased from the original tree." << endl;
    }

    void createMirrorImage() {
        TreeNode* mirror = mirrorImage(root);
        cout << "Mirror image of the tree created successfully." << endl;

        eraseTree(root);
        root = mirror;
    }
};

int main() {
    BST bst;
    int choice, value;

    do {
        cout << "----- Binary Search Tree Operations -----" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Find the height of the tree" << endl;
        cout << "3. Create a clone of the tree and erase all nodes in the original tree" << endl;
        cout << "4. Create a mirror image of the tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                break;

            case 2:
                bst.findTreeHeight();
                break;

            case 3:
                bst.createCloneAndErase();
                break;

            case 4:
                bst.createMirrorImage();
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}
