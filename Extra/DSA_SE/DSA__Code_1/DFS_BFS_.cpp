#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 100;

vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void dfs(int start, int n) {
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

void bfs(int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. DFS Traversal\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int start;
                cout << "Enter the starting vertex for DFS traversal: ";
                cin >> start;
                dfs(start, n);
                break;
            case 2:
                cout << "Enter the starting vertex for BFS traversal: ";
                cin >> start;
                bfs(start, n);
                break;
            case 3:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}