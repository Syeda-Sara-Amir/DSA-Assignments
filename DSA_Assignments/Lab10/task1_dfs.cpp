#include <iostream>
using namespace std;

bool visited[10];

void dfs(int graph[][10], int vertices, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, vertices, i);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    int graph[10][10] = {0};
    for (int i = 0; i < 10; i++) visited[i] = false;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(graph, vertices, start);
    cout << endl;

    return 0;
}
