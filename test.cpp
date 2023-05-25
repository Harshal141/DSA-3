#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
private:
	unordered_map<int, vector<int> >
		graph; 
	int V; 
public:
	Graph(int vertices)
		: V(vertices)
	{
	}

	// function to add an edge to graph
	void addEdge(int u, int v) { graph[u].push_back(v); }

	void nonRecursiveTopologicalSort()
	{
		vector<bool> visited(
			V,
			false); // mark all the vertices as not visited
		stack<int> stack; // result stack

		// call the helper function to store Topological
		// Sort starting from all vertices one by one
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				nonRecursiveTopologicalSortUtil(i, visited,
												stack);
			}
		}

		// print contents of the stack in reverse
		vector<int> sorted;
		while (!stack.empty()) {
			sorted.push_back(stack.top());
			stack.pop();
		}
		cout << "The following is a Topological Sort "
					"of the given graph:\n";
		for (auto& i : sorted) {
			cout << i << " ";
		}
		cout << endl;
	}

private:
	// helper function for non-recursive topological sort
	void nonRecursiveTopologicalSortUtil(
		int v,vector<bool>& visited,
		stack<int>& stack)
	{
		visited[v] = true;

		for (auto& next_neighbor : graph[v]) {
			if (!visited[next_neighbor]) {
				nonRecursiveTopologicalSortUtil(
					next_neighbor, visited, stack);
			}
		}
		stack.push(v);
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0, 3);
	g.addEdge(0, 1);
	g.addEdge(3, 4);
	g.addEdge(1, 4);
	g.addEdge(5, 4);
	g.addEdge(0, 2);

	g.nonRecursiveTopologicalSort();
	return 0;
}
