/*
Title: Write a menu driven C++ program to implement Minimum Cost Spanning Trees. 
Problem Statement: You have a business with several offices; you want to lease phone lines 
to connect them up with each other; and the phone company charges different amounts of 
money to connect different pairs of cities. You want a set of lines that connects all your offices 
with a minimum total cost. Solve the problem by suggesting appropriate data structures and 
using: 
1. Prims Algorithm 
2. Kruskals Algorithm 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    vector<Edge> edges;

    Graph(int numVertices) {
        this->numVertices = numVertices;
    }

    void addEdge(int source, int destination, int weight) {
        edges.push_back(Edge(source, destination, weight));
    }
};

// Comparator for sorting edges in ascending order of weight
struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }
};

// Find the parent of a vertex in a disjoint set
int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return findParent(parent, parent[vertex]);
}

// Perform Union operation on two sets in a disjoint set
void performUnion(vector<int>& parent, int x, int y) {
    int parentX = findParent(parent, x);
    int parentY = findParent(parent, y);

    parent[parentY] = parentX;
}

// Prim's algorithm for finding the Minimum Cost Spanning Tree
void primMST(const Graph& graph) {
    int numVertices = graph.numVertices;

    // Vector to track the parent of each vertex in MST
    vector<int> parent(numVertices);

    // Vector to track the minimum weight edge to connect each vertex in MST
    vector<int> minWeight(numVertices, INT_MAX);

    // Vector to track whether a vertex is included in MST or not
    vector<bool> included(numVertices, false);

    // Start with the first vertex
    int startVertex = 0;
    minWeight[startVertex] = 0;
    parent[startVertex] = -1;

    for (int i = 0; i < numVertices - 1; i++) {
        // Find the vertex with minimum weight that is not yet included in MST
        int minWeightVertex = -1;
        for (int v = 0; v < numVertices; v++) {
            if (!included[v] && (minWeightVertex == -1 || minWeight[v] < minWeight[minWeightVertex])) {
                minWeightVertex = v;
            }
        }

        // Include the minimum weight vertex in MST
        included[minWeightVertex] = true;

        // Update the minimum weight and parent for adjacent vertices
        for (const Edge& edge : graph.edges) {
            if (edge.source == minWeightVertex && !included[edge.destination] && edge.weight < minWeight[edge.destination]) {
                minWeight[edge.destination] = edge.weight;
                parent[edge.destination] = minWeightVertex;
            }
            if (edge.destination == minWeightVertex && !included[edge.source] && edge.weight < minWeight[edge.source]) {
                minWeight[edge.source] = edge.weight;
                parent[edge.source] = minWeightVertex;
            }
        }
    }

    // Print the MST
    cout << "Minimum Cost Spanning Tree (Prim's algorithm):" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}

// Kruskal's algorithm for finding the Minimum Cost Spanning Tree
void kruskalMST(const Graph& graph) {
    int numVertices = graph.numVertices;
    vector<Edge> mstEdges;

    // Sort the edges in ascending order of weight
    vector<Edge> sortedEdges = graph.edges;
    sort(sortedEdges.begin(), sortedEdges.end(), Compare());

    // Vector to track the parent of each vertex in disjoint set
    vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    // Perform Union-Find algorithm to find MST
    for (const Edge& edge : sortedEdges) {
        int parentSource = findParent(parent, edge.source);
        int parentDestination = findParent(parent, edge.destination);

        // Include the edge in MST if it does not form a cycle
        if (parentSource != parentDestination) {
            mstEdges.push_back(edge);
            performUnion(parent, parentSource, parentDestination);
        }
    }

    // Print the MST
    cout << "Minimum Cost Spanning Tree (Kruskal's algorithm):" << endl;
    for (const Edge& edge : mstEdges) {
        cout << edge.source << " - " << edge.destination << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph graph(numVertices);

    cout << "Enter the source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int choice;

    do {
        cout << "\n----- Minimum Cost Spanning Trees Menu -----";
        cout << "\n1. Find Minimum Cost Spanning Tree using Prim's algorithm";
        cout << "\n2. Find Minimum Cost Spanning Tree using Kruskal's algorithm";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                primMST(graph);
                break;
            case 2:
                kruskalMST(graph);
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}
