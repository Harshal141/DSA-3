/*
Title: Write a menu driven C++ program to implement binary tree/binary search tree with n 
nodes. 
do following operation 
1. Insert a node in a BST 
2. delete a node from BST 
3. Search node 
4. All traversals (recursive) 
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

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                TreeNode* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
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

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node inserted successfully." << endl;
    }

    void remove(int value) {
        TreeNode* node = searchNode(root, value);
        if (node == nullptr) {
            cout << "Node not found." << endl;
        } else {
            root = deleteNode(root, value);
            cout << "Node deleted successfully." << endl;
        }
    }

    void search(int value) {
        TreeNode* node = searchNode(root, value);
        if (node == nullptr) {
            cout << "Node not found." << endl;
        } else {
            cout << "Node found." << endl;
        }
    }

    void traverse() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        } else {
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << endl;

            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            cout << endl;

            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
        }
    }
};

int main() {
    BST bst;
    int choice, value;

    do {
        cout << "----- Binary Search Tree Operations -----" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Search a node" << endl;
        cout << "4. Perform all traversals" << endl;
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
                cout << "Enter the value to delete: ";
                cin >> value;
                bst.remove(value);
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                bst.search(value);
                break;

            case 4:
                bst.traverse();
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
