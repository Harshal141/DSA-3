#include<bits/stdc++.h>
using namespace std;

// int preIndex = 0;
class Node{
    public:
    char data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data){
        this->data = data;
    }
};
 int preIndex = 0;
Node* Tree(char in[],char pre[],int inStart,int inEnd){
    if(inStart > inEnd)return NULL;
    Node* temp = new Node(pre[preIndex]);
    preIndex++;
    if(inStart == inEnd)return temp;
    int i;
    for(i=inStart;i<=inEnd;i++){
        if(in[i]==temp->data)break;
    }

    temp->left = Tree(in,pre,inStart,i-1);
    temp->right = Tree(in,pre,i+1,inEnd);

    return temp;

};

void innerPrint(Node* temp){
    if(temp->left!=NULL)innerPrint(temp->left);
    cout << temp->data << " ";
    if(temp->right!=NULL)innerPrint(temp->right);
}

int main(){
    cout << "test";
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    Node* head = Tree(in,pre,0,5);
    // cout << head->le;
    innerPrint(head);
}