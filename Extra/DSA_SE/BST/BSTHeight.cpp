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
        void del(int key){
            Node* temp = head;
            while(true){
                if(temp->val==key)break;
                if(temp->val < key){
                    temp = temp->right;
                    continue;
                }
                temp = temp->left;
            }
            if(temp->left == NULL && temp->right == NULL){
                if(temp->parent == NULL)head = NULL;
                if(temp->parent->val < temp->val)temp->parent->right = NULL;
                if(temp->parent->val > temp->val)temp->parent->left = NULL;
                delete temp;
                return;
            }
            if(temp->left == NULL && temp->right !=NULL){
                if(temp->parent == NULL)head = temp->right;
                if(temp->parent->val < temp->val)temp->parent->right = temp->right;
                if(temp->parent->val > temp->val)temp->parent->left = temp->right;
                return;
            }
            if(temp->left != NULL && temp->right ==NULL){
                if(temp->parent == NULL)head = temp->left;
                if(temp->parent->val < temp->val)temp->parent->right = temp->left;
                if(temp->parent->val > temp->val)temp->parent->left = temp->left;
                return;
            }
            Node* finder = temp->right;
            while(true){
                if(finder->left == NULL)break;
                finder = finder->left;
            }
            if(finder->right !=NULL){
                finder->parent->left = finder->right;
            }
            temp->val = finder->val;
            return;

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

};



int main(){
    cout << "test";
    BST* tree = new BST;
    tree->insert(10);
    tree->insert(20);
    tree->insert(5);
    tree->insert(1);
    tree->print();
    // tree->del(5);
    // cout << height(tree->head) ;

}