#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(a==b)return a;
    if(a<b){
        b-=a;
        gcd(a,b);
    }
    else{
        a-=b;
        gcd(a,b);
    }
}

void solution(){
    int a = 24,b=72;
    if (a==0)cout << b;
    else if(b==0)cout << a;
    else{
    int c = gcd(a,b);
    cout << c;
    }
}

int main()
{   
    // vector<vector<int>> matrix = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12}
    // };

    solution();
}