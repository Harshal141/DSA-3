/*
Title: Write a menu driven C++ program to implement binary tree/binary search tree with n 
nodes. 
do following operation 
1. Insert a node in a BST 
2. delete a node from BST 
3. construct a binary tree from inorder and preorder traversal 
4. Check whether two trees are equal. 
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

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* minNode = findMinNode(node->right);
            node->data = minNode->data;
            node->right = deleteNode(node->right, minNode->data);
        }

        return node;
    }

    TreeNode* buildTreeFromInorderPreorder(int inorder[], int preorder[], int start, int end) {
        static int preIndex = 0;

        if (start > end) {
            return nullptr;
        }

        TreeNode* node = createNode(preorder[preIndex++]);

        if (start == end) {
            return node;
        }

        int inIndex;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == node->data) {
                inIndex = i;
                break;
            }
        }

        node->left = buildTreeFromInorderPreorder(inorder, preorder, start, inIndex - 1);
        node->right = buildTreeFromInorderPreorder(inorder, preorder, inIndex + 1, end);

        return node;
    }

    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        if (root1->data != root2->data) {
            return false;
        }

        bool leftSubtreeIdentical = isIdentical(root1->left, root2->left);
        bool rightSubtreeIdentical = isIdentical(root1->right, root2->right);

        return leftSubtreeIdentical && rightSubtreeIdentical;
    }

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node inserted successfully." << endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
        cout << "Node deleted successfully." << endl;
    }

    void constructTreeFromInorderPreorder() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        int* inorder = new int[n];
        int* preorder = new int[n];

        cout << "Enter the inorder traversal: ";
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }

        cout << "Enter the preorder traversal: ";
        for (int i = 0; i < n; i++) {
            cin >> preorder[i];
        }

        root = buildTreeFromInorderPreorder(inorder, preorder, 0, n - 1);
        cout << "Binary tree constructed successfully." << endl;

        delete[] inorder;
        delete[] preorder;
    }

    bool checkTreeEquality() {
        BST tree1;
        BST tree2;

        cout << "Enter the elements for the first tree (-1 to stop): ";
        int value;
        while (cin >> value && value != -1) {
            tree1.insert(value);
        }

        cout << "Enter the elements for the second tree (-1 to stop): ";
        while (cin >> value && value != -1) {
            tree2.insert(value);
        }

        bool isEqual = isIdentical(tree1.root, tree2.root);

        if (isEqual) {
            cout << "The two trees are equal." << endl;
        } else {
            cout << "The two trees are not equal." << endl;
        }

        return isEqual;
    }
};

int main() {
    BST bst;
    int choice, value;

    do {
        cout << "----- Binary Search Tree Operations -----" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Construct a binary tree from inorder and preorder traversal" << endl;
        cout << "4. Check whether two trees are equal" << endl;
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
                bst.constructTreeFromInorderPreorder();
                break;

            case 4:
                bst.checkTreeEquality();
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
