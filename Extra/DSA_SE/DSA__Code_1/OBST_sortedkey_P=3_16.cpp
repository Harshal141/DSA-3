/*
Title: Write a C++ program to implement Optimal Binary Search Tree. 
Problem Statement: Given sequence k = k1<; k2<.... kn of n sorted keys, with a search 
probability pi for each key ki . Build the Binary search tree that has the least search cost given 
the access probability for each key. Test your program for following example 
p1 = 3, p2 = 3, p3 = 1, p4 = 1 
q0 = 2, q1 = 3, q2 = 1, q3= 1, q4 = 1 
1. Find optimal cost of tree 
2. Display root of tree
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int w[N][N];
int r[N][N];
int c[N][N];
int p[N];
int q[N];

int main() {
    cout << "ENTER NO. OF ELEMENTS: ";
    int n; cin >> n;
    cout << "ENTER SUCCESS PROBABILITY: ";
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "ENTER UNSUCCESS PROBABILITY: ";
    for(int i = 0; i <= n; i++) {
        cin >> q[i];
    }
    for(int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] = i+1;
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    for(int d = 2; d <= n; d++) {
        for(int j = d; j <= n; j++) {
            int i = j-d;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            int mn = INT_MAX;
            int mnk;
            for(int k = i+1; k <= j; k++) {
                int x = c[i][k-1] + c[k][j];
                if(x < mn) {
                    mn = x;
                    mnk = k;
                }
            }
            c[i][j] = w[i][j] + mn;
            r[i][j] = mnk;
        }
    }
    cout << "WEIGHT OF OBST: " << w[0][n] << endl;
    cout << "COST OF OBST: " << c[0][n] << endl;
    cout << "ROOT OF OBST: " << r[0][n]<<endl;
    return 0;
}