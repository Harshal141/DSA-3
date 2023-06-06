#include<bits/stdc++.h>
using namespace std;

class Db{
    public:
        int size = 1;
        struct Node{
            int key = -1;
            int value = -1;
            Node* next = NULL;
        };
        Node* table;
        Db(int size){
            this->size = size;
            table = new Node[size];
        }
        void insert(int key,int value){
            int index = key%size;
            Node* temp = new Node;
            temp->key = key;
            temp->value = value;
            if(table[index].next == NULL){
                table[index].next = temp;
            }else{
                Node* tempa = table[index].next;
                while(tempa->next!=NULL){
                    tempa = tempa->next;
                }
                tempa->next = temp;
            }
        }
};

int main(){
    Db* temp = new Db(3);
    temp->insert(1,10);
    
    temp->insert(1,20);
    temp->insert(1,30);
    cout << temp->table[1].next->value;
}