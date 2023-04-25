#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solution(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int sc=0,sr =0;
    int ec = col-1;
    int er = row-1;
    int count = 0;
    int total = row*col;
    // count printed values
    while(count < total){
        //first row print
        for(int i=sc;i<=ec;i++){
            cout << matrix[sr][i] << " ";
            count++;
        }
        sr++;
        if(count == total)break;
        //first col
        for(int i=sr;i<=er;i++){
            cout << matrix[i][ec] << " ";
            count++;
        }
        ec--;
        if(count == total)break;
        // last row
        for(int i=ec;i>=sc;i--){
            cout << matrix[er][i] << " ";
            count++;
        }
        er--;
        if(count == total)break;
        // first col
        for(int i=er;i>=sr;i--){
            cout << matrix[i][sc] << " ";
            count++;
        }
        sc++;
        if(count == total)break;
    }
}

int main()
{   
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    solution(matrix);
}