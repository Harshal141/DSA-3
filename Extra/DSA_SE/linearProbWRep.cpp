// Linear probing without replacement

#include<bits/stdc++.h>
using namespace std;

class Db{
    public:
        int size =1;
        struct student{
            int key =-1;
            int value=-1;
            int chain = -1;
        };
        student* table = NULL;
        Db(int size){
            this->size = size;
            table = new student[size];
        }
        void insert(int keyin,int valuein){
            int index = keyin%size;
            int original = index;
            int looper = 0;
            cout << keyin << " " << index << " " << table[index].key << " " << table[index].chain << endl;
            while(table[index].key != -1){
                looper = 1;
                index = (index+1)%size;
                cout << keyin << " " << index << " " << table[index].key << " " << table[index].chain << endl;
            }
            table[index].key = keyin;
            table[index].value = valuein;
            if(looper){
                while(table[original].chain !=-1){
                    original = table[original].chain;
                }
                table[original].chain = index;
            }
        }
        void search(int keyin){
            int index = keyin%size;
            while(table[index].key != keyin ){
                index = (index+1)%size;
            }
            cout << table[index].value;
        }
};

int main(){

    Db* temp = new Db(4);
    temp->insert(6,1);
    temp->insert(8,2);
    temp->insert(2,3);
    temp->insert(18,4);
    cout << temp->table[3].chain;
    // temp->search(8);

}