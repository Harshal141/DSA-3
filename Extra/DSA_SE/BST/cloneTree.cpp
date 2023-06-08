#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left = NULL;
        Node* right = NULL;
        Node* parent = NULL;
        Node(int val){
            this->val = val;
        }
};

int height(Node* temp){
    if(temp == NULL)return 0;
    return max(height(temp->left),height(temp->right))+1;
}

class BST{
    public:
        Node* head = NULL;
        void insert(int val){
            Node* temp = new Node(val);
            if (head == NULL){head = temp;return;}
            Node* pointer = head;
            while(true){
                if(pointer->val < val){
                    if(pointer->right == NULL){
                        temp->parent = pointer;
                        pointer->right = temp;
                        break;
                    }
                    pointer = pointer->right;
                    continue;
                }
                if(pointer->left == NULL){
                    temp->parent = pointer;
                    pointer->left = temp;
                    break;
                }
                pointer = pointer->left;
            }
        }
        void print(){
            Node* temp = head;
            innerPrint(temp);
        }
        void innerPrint(Node* temp){
            if(temp->left!=NULL)innerPrint(temp->left);
            cout << temp->val << " ";
            if(temp->right!=NULL)innerPrint(temp->right);
        }
        Node* clone(Node* root){
            if(root == NULL) return NULL;
            Node* temp = new Node(root->val);
            temp->left = clone(root->left);
            temp->right = clone(root->right);
            return temp;
        }
        void remove(Node* root){
            if(root == NULL)return;
            remove(root->left);
            remove(root->right);
            delete root;
        }

};



int main(){
    BST* tree = new BST;
    tree->insert(10);
    tree->insert(20);
    tree->insert(5);
    tree->insert(1);
    // tree->print();
    Node* neww = tree->clone(tree->head);
    tree->innerPrint(neww);
    tree->remove(neww);
    cout << neww->left;
    // tree->innerPrint(neww);
    

    // tree->del(5);
    // cout << height(tree->head) ;

}