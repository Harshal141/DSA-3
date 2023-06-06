#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        Node* mom = NULL;
        Node* left = NULL;
        Node* right = NULL;
        int key;
        int height;
        int balance;
    
    Node(int key){
        this->key = key;
    }
};

void balance(Node* it){
    if(it->left == NULL && it->right == NULL){
        it->height = 0;
        it->balance = 0;
    }else if(it->left == NULL){
        it->height = it->right->height + 1;
        it->balance = -1 * (it->right->height + 1);
    }else if(it->right == NULL){
        it->height = it->left->height + 1;
        it->balance = it->left->height + 1;
    }else{
        it->height = max(it->left->height, it->right->height) + 1;
        it->balance = it->left->height - it->right->height;
    }
}

void balanceRec(Node *temp){
    if(temp == NULL)return;
    balanceRec(temp->left);
    balanceRec(temp->right);
    balance(temp);
}

// balance tree rotations

void leftRot(Node* it,Node* head){
    Node* temp = it->mom;
    Node* temp2 = temp->mom;
    temp->right = it->left;
    it->left = temp;
    temp->mom = it;
    it->mom = temp2;
    if(temp2 != NULL){
        if(temp2->left == temp){
            temp2->left = it;
        }else{
            temp2->right = it;
        }
    }else{
        head = it;
    }
    balanceRec(temp);
}

void rightRot(Node* it,Node* head){
    Node* temp = it->mom;
    Node* temp2 = temp->mom;
    temp->left = it->right;
    it->right = temp;
    temp->mom = it;
    it->mom = temp2;
    if(temp2 != NULL){
        if(temp2->left == temp){
            temp2->left = it;
        }else{
            temp2->right = it;
        }
    }else{
        head = it;
    }
    balanceRec(temp);
}

class Tree{
    public:
        Node* head = NULL;
        // Node* temp = new Node(99);

        void print(Node *temp){
            if(temp == NULL)return;
            print(temp->left);
            cout<<temp->key<<" " << temp->height<<" "<<temp->balance<<endl;
            print(temp->right);
        }

        void insert(int key){
            Node* temp = new Node(key);

            if(head == NULL){
                head = temp;
                head->height = 0;
                head->balance = 0;
                return;
            }else{
                Node* it = head;
                while(it !=NULL){
                    if(key < it->key){
                        if(it->left == NULL){
                            it->left = temp;
                            temp->mom = it;
                            return;
                        }else{
                            it = it->left;
                        }
                    }else{
                        if(it->right == NULL){
                            it->right = temp;
                            temp->mom = it;
                            return;
                        }else{
                            it = it->right;
                        }
                    }
                }
            }
            mainBalanace(head);
            // balanceRec(head);

            // rotations

        }

};

int main(){
    Tree* tree = new Tree();
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    balanceRec(tree->head);
    tree->print(tree->head);
    Node* test = tree->head->right->right;
    leftRot(test,tree->head);
    leftRot(test,tree->head);
    tree->print(tree->head);

    return 0;
}