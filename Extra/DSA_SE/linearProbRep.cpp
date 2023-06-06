// linear probing with probing with replacement
#include<bits/stdc++.h>
using namespace std;

class Db{
    public:
        struct Node{
            int key = -1;
            int value = -1;
            int chain = -1;
            int from = -1;
        };
        int size =1;
        Node* table;
        Db(int size){
            this->size = size;
            table = new Node[size];
        }
        void insert(int key ,int value){
            int index = key%size;
            int original = index;
            int prob = 0;
            int isRep = 0;
            if(table[index].key != -1 && (table[index].key)%size != index ){
                cout << "prob for" << key <<" " << index<<  endl;
                // store the replace value
                int moveKey = table[index].key;
                int moveValue = table[index].value;
                int moveChain = table[index].chain;
                int moveFrom = table[index].from;

                table[index].key = key;
                table[index].value = value;
                table[index].chain = table[index].from = -1;

                while(table[index].key != -1){
                    index = (index+1)%size;
                }
                table[index].key = moveKey;
                table[index].value = moveValue;
                table[index].from = moveFrom;
                table[index].chain = moveChain;

                // update chain
                table[moveFrom].chain = index;
                
                return;
            }
            while(table[index].key != -1){
                prob = 1;
                index = (index+1)%size;
            }
            table[index].key = key;
            table[index].value = value;
            if(prob){
                while(table[original].chain != -1){
                    original = table[original].chain;
                }
                table[original].chain = index;
                table[index].from = original;
            }
        }
        void print(){
            for(int i=0;i<size;i++){
                cout <<i << " " <<  table[i].key << " " << table[i].chain << " " << table[i].from << endl;
            }
        }
};

int main(){
    cout << "test";
    Db* temp = new Db(4);
    temp->insert(8,1);
    temp->insert(6,2);
    temp->insert(2,3);
    temp->insert(7,4);
    temp->print();
    // cout << temp->table[2].chain;
    // cout << temp->table[3].chain;
}