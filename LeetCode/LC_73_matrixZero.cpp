#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int x[200] = {0};
    int y[200] = {0};
    // cout << matrix.size() << matrix[0].size();
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] == 0){
                x[i] = 1;y[j] =1;
            }
            // cout << matrix[i][j]<< " ";
        }
        // cout << endl;
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(x[i] ==0 && y[j] == 0){
                cout << matrix[i][j] << " ";
                continue;
            }else{
                matrix[i][j] == 0;
            }
        }
    }
    // for(int  i=0;i<matrix.size();i++){
    //     if(x[i]){
    //         for(int j=0;j<matrix[0].size();j++){
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }
    // for(int  j=0;j<matrix[0].size();j++){
    //     if(y[j]){
    //         for(int i=0;i<matrix.size();i++){
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}


// optimal take the int x[200] = {0};
// int y[200] = {0}; as the first row and col
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//     int col0 = 1;
//     for(int i=0;i<matrix.size();i++){
//         for(int j=0;j<matrix[0].size();j++){
//             if(matrix[i][j] == 0){
//                 matrix[i][0] = 0;
//                 if(j == 0){
//                     col0 = 0;
//                 }else{
//                     matrix[0][j] = 0;
//                 }
//             }
//         }
//     }

//     // iterration without col 0 and row 0;
//     for(int i= matrix.size()-1;i>0;i--){
//         for(int j = matrix[0].size()-1;j>0;j--){
//             if(matrix[0][j] == 0 || matrix[i][0]==0){
//                 matrix[i][j]= 0;
//             }
//         }
//     }
//     // col 0 and row 0 update
//     if(matrix[0][0] == 0){
//         for(int i=0;i<matrix[0].size();i++){
//             matrix[0][i] = 0;
//         }
//     }
//     if(col0 == 0){
//         for(int i=0;i<matrix.size();i++){
//             matrix[i][0] = 0;
//         }
//     }
//     }
// };
