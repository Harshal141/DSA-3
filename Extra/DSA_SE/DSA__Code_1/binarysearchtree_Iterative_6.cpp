/*
Title: Write a menu driven C++ program to implement binary tree/binary search tree with n 
nodes. 
do following operation 
1. Insert a node in a BST 
2. Search a node in a BST 
3. All traversals (Iterative) 
4. Find the height of a tree 
*/

#include <iostream>
#include <stack>
#include <queue>
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

    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    void inorderTraversalIterative() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        stack<TreeNode*> stk;
        TreeNode* current = root;

        cout << "Inorder Traversal (Iterative): ";
        while (current != nullptr || !stk.empty()) {
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

            current = stk.top();
            stk.pop();

            cout << current->data << " ";

            current = current->right;
        }
        cout << endl;
    }

    void preorderTraversalIterative() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        stack<TreeNode*> stk;
        stk.push(root);

        cout << "Preorder Traversal (Iterative): ";
        while (!stk.empty()) {
            TreeNode* current = stk.top();
            stk.pop();

            cout << current->data << " ";

            if (current->right != nullptr) {
                stk.push(current->right);
            }

            if (current->left != nullptr) {
                stk.push(current->left);
            }
        }
        cout << endl;
    }

    void postorderTraversalIterative() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);

        cout << "Postorder Traversal (Iterative): ";
        while (!stk1.empty()) {
            TreeNode* current = stk1.top();
            stk1.pop();
            stk2.push(current);

            if (current->left != nullptr) {
                stk1.push(current->left);
            }

            if (current->right != nullptr) {
                stk1.push(current->right);
            }
        }

        while (!stk2.empty()) {
            TreeNode* node = stk2.top();
            stk2.pop();
            cout << node->data << " ";
        }
        cout << endl;
    }

    int findHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }

        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node inserted successfully." << endl;
    }

    void search(int value) {
        TreeNode* node = searchNode(root, value);
        if (node == nullptr) {
            cout << "Node not found." << endl;
        } else {
            cout << "Node found." << endl;
        }
    }

    void performTraversals() {
        inorderTraversalIterative();
        preorderTraversalIterative();
        postorderTraversalIterative();
    }

    void findTreeHeight() {
        int height = findHeight(root);
        cout << "Height of the tree: " << height << endl;
    }
};

int main() {
    BST bst;
    int choice, value;

    do {
        cout << "----- Binary Search Tree Operations -----" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Search a node" << endl;
        cout << "3. Perform all traversals (Iterative)" << endl;
        cout << "4. Find the height of a tree" << endl;
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
                cout << "Enter the value to search: ";
                cin >> value;
                bst.search(value);
                break;

            case 3:
                bst.performTraversals();
                break;

            case 4:
                bst.findTreeHeight();
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
