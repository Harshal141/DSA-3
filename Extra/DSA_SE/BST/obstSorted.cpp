#include<bits/stdc++.h>
using namespace std;

const int m = 100;
int w[m][m];
int r[m][m];
int c[m][m];
int p[m];
int q[m];

int main(){

    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int temp;cin >> temp;
        p[i] = temp;
    }
    cout << "test";
    for(int i=0;i<=n;i++){
        int temp;cin >> temp;
        q[i] = temp;
    }
    for(int i=0;i<=n;i++){
        w[i][i] = q[i];
        r[i][i] = c[i][i] = 0;
    }
    for(int i=0;i<n;i++){
        w[i][i+1] = q[i]+ q[i+1]+p[i+1];
        r[i][i+1] = i+1;
        c[i][i+1] = q[i]+ q[i+1]+p[i+1];
    }
    for(int d= 2;d<=n;d++){
        for(int j=d;j<=n;j++){
            int i = j-d;
            w[i][j] = w[i][j-1] + q[j]+p[j];
            int min = INT_MAX;
            int mnk ;
            for(int k = i+1;k<=j;k++){
                int x = c[i][k-1]+c[k][j];
                if(x<min){
                    min = x;mnk = k;
                }
            }
            c[i][j] = w[i][j]+min;
            r[i][j] = mnk;
        }
    }

    cout << w[0][n] << endl;
    cout << c[0][n] << endl;
    cout << r[0][n] << endl;
}