#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    char data='$';
    int freq = 0;
    Node* one = NULL;
    Node* two = NULL;
    Node(char d,int f){
        this->data = d;
        this->freq = f;
    }
};

void print(Node* head,string s){
    if(head == NULL)return;
    if(head->data!='$'){
        cout << head->data << " " << s <<endl;
    }
    print(head->one,s+'1');
    print(head->two,s+'0');
}

int main(){
    cout << "test";
    // vector<Node*> arr;
    Node* a = new Node('a',15);
    Node* b = new Node('b',1);
    Node* c = new Node('c',5);
    Node* d = new Node('d',8);
    multimap<int,Node*> map;
    map.insert({15,a});
    map.insert({1,b});
    map.insert({5,c});
    map.insert({8,d});

    while(map.size()!=1){
        Node* one = map.begin()->second;
        map.erase(map.begin());
        Node* two = map.begin()->second;
        map.erase(map.begin());
        Node* neww = new Node('$',int(one->freq)+int(two->freq));
        neww->one = one;
        neww->two = two;
        map.insert({int(one->freq)+int(two->freq),neww});
    }
    print(map.begin()->second,"");
    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);
    // arr.push_back(d);
    // cout << arr[0]->data;
    // while(arr.size()!=1){
    //     int max = 0;
    //     int in = 0;
    //     for(int i=0;i<arr.size();i++){
    //         if(arr[i]->data > max){
    //             max = arr[i]->data;
    //             in = i;
    //         }
    //     }
    //     Node* first = 
    //     max = in = 0;
    // }
}