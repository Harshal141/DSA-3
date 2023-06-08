#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left = NULL;
        Node* right = NULL;
        Node* parent = NULL;
        bool isT = false;
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
            // while do loop 
        }
        Node* threaderR(Node* root){
            if(root == NULL)return  NULL;
            if(root->left == NULL && root->right ==NULL){
                return root;
            }
            if(root->left!=NULL){
                Node* l = threaderR(root->left);
                l->right = root;
                l->isT = true;
            }
            if(root->right ==NULL){
                return root;
            }
            return threaderR(root->right);
        }

};



int main(){
    cout << "test";
    BST* tree = new BST;
    tree->insert(10);
    tree->insert(20);
    tree->insert(5);
    tree->insert(1);
    // tree->print();
    tree->threaderR(tree->head);
    cout << tree->head->left->isT;
    // tree->del(5);
    // cout << height(tree->head) ;

}