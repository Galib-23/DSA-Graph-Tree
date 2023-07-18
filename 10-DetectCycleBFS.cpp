#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isCyclic(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        for (int adjacentVertex : graph[currentVertex]) {
            if (!visited[adjacentVertex]) {
                q.push(adjacentVertex);
                visited[adjacentVertex] = true;
            } else {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int numVertices = 4;
    vector<vector<int>> graph(numVertices);
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    int startVertex = 0; 
    bool hasCycle = isCyclic(graph, startVertex);
    if (hasCycle)
        cout << "Cycle detected in the graph\n";
    else
        cout << "No cycle detected in the graph\n";
    return 0;
}
