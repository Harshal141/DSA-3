/*
Title : Write a c++ program to print topological order of given Directed acyclic Graph.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Depth-First Search (DFS) function for topological sorting
void dfsTopological(int currentVertex, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stk) {
    visited[currentVertex] = true;

    // Recursively visit all adjacent vertices
    for (int neighbor : graph[currentVertex]) {
        if (!visited[neighbor]) {
            dfsTopological(neighbor, graph, visited, stk);
        }
    }

    // Push the current vertex to the stack after all its neighbors have been visited
    stk.push(currentVertex);
}

// Function to perform topological sorting
void topologicalSort(const vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    stack<int> stk;

    // Call DFS for every unvisited vertex
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfsTopological(i, graph, visited, stk);
        }
    }

    // Print the topological order
    cout << "Topological Order: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Create a graph representation using adjacency list
    vector<vector<int>> graph(numVertices);

    cout << "Enter the source and destination for each edge:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
    }

    // Perform topological sorting
    topologicalSort(graph, numVertices);

    return 0;
}
