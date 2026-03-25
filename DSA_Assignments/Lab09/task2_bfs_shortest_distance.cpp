#include <iostream>
#include <queue>
using namespace std;

void bfsDistance(int graph[][10], int vertices, int start) {
    int distance[10];
    bool visited[10] = {false};

    for (int i = 0; i < vertices; i++) distance[i] = -1;

    queue<int> q;
    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[node] + 1;
                q.push(i);
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":" << endl;
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == -1)
            cout << "Vertex " << i << " : Unreachable" << endl;
        else
            cout << "Vertex " << i << " : " << distance[i] << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    int graph[10][10] = {0};

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

    bfsDistance(graph, vertices, start);
    return 0;
}
