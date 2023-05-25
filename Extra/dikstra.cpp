#include<bits/stdc++.h>
using namespace std;

int minner(int graph[9][9], int current,int visited[9],int tagAlong[9]){
    int min = INT_MAX;int temp = -1;
    for(int i=0;i<9;i++){
        if(visited[i])continue;
        if(graph[current][i] == 0) continue;
        if(min > tagAlong[i]){
            min = tagAlong[i];
            temp = i;
        }
    }
    return temp;
}

int main(){
    // making the bridges
    int graph[9][9]= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int ans[9];
    for(int i=0;i<9;i++){
        ans[i] = INT_MAX;
    }
    ans[0] = 0;
    int visited[9] = {false};
    int current =0;
    int tagAlong[9] = {0};


    for(int i=0;i<9;i++){
        visited[current] = true;
        // update the ans from here
        for(int i=0;i<9;i++){
            if(graph[current][i] == 0) continue;
            if(ans[i] > graph[current][i]+tagAlong[current]){
                ans[i] = graph[current][i]+tagAlong[current];
                tagAlong[i] = ans[i];
            }
        }
        // find min
        int min = minner(graph,current,visited,tagAlong);
        cout << min << " " ;
        if(min == -1)break;
        current = min;
    }
    for(int i=0;i<9;i++){
        cout << ans[i] << endl;
    }

}