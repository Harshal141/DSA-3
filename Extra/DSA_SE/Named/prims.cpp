#include<bits/stdc++.h>
using namespace std;

void prims(int graph[5][5]){
    int dist[5],parent[5];
    bool visited[5];
    for(int i=0;i<5;i++){
        dist[i] = INT_MAX;visited[i] = false;
        parent[i]=-1;
    }
    dist[0] = 0;
    for(int i=0;i<5;i++){
        int min = INT_MAX;int u;
        for(int i=0;i<5;i++){
            if(dist[i] < min && visited[i] == false){
                u = i;min = dist[i];
            }
            visited[u] = true;

            for(int i=0;i < 5;i++){
                if(graph[u][i] != 0 && dist[i] > graph[u][i]){
                    parent[i] = u;
                    dist[i] = graph[u][i];
                }
            }
        }
    }
    for(int i=1;i<5;i++){
        cout << i << " " << parent[i] << " " << dist[i] << endl;
    }
}

int main(){
    cout << " test";
    int v = 5;
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    prims(graph);
}