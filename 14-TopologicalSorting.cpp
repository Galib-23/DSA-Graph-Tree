#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfsTopologicalSort(vector<vector<int>>& graph, int vertex, vector<bool>& visited, stack<int>& sortedStack) {
    visited[vertex] = true;

    for (int adjacentVertex : graph[vertex]) {
        if (!visited[adjacentVertex]) {
            dfsTopologicalSort(graph, adjacentVertex, visited, sortedStack);
        }
    }
    sortedStack.push(vertex);
}
void topologicalSort(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    stack<int> sortedStack;

    for (int vertex = 0; vertex < numVertices; ++vertex) {
        if (!visited[vertex]) {
            dfsTopologicalSort(graph, vertex, visited, sortedStack);
        }
    }
    cout << "Topological Sorting: ";
    while (!sortedStack.empty()) {
        cout << sortedStack.top() << " ";
        sortedStack.pop();
    }
    cout << "\n";
}
int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    topologicalSort(graph, numVertices);

    return 0;
}
