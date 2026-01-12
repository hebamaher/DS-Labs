#include <iostream>
#include <queue>
using namespace std;

#define N 10

int graph[N][N] = {
 {0,1,0,1,0,0,0,0,0,0},
 {1,0,1,0,1,0,1,1,0,0},
 {0,1,0,1,0,0,0,0,1,1},
 {1,0,1,0,0,0,0,0,0,0},
 {0,1,0,0,0,1,1,1,0,0},
 {0,0,0,0,1,0,0,0,0,0},
 {0,1,0,0,1,0,0,1,0,0},
 {0,1,0,0,1,0,1,0,0,0},
 {0,0,1,0,0,0,0,0,0,0},
 {0,0,1,0,0,0,0,0,0,0}
};

void printAdjMatrix(int graph[10][10]) {
    cout << "Adjacency Matrix:\n\n    ";

    // Column headers
    for (int i = 1; i <= 10; i++)
        cout << i << " ";
    cout << "\n\n";

    // Rows
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 10; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int start) {
    bool visited[N] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v + 1 << " ";

        for (int i = 0; i < N; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void DFS(int v, bool visited[]) {
    visited[v] = true;
    cout << v + 1 << " ";

    for (int i = 0; i < N; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i, visited);
    }
}

int main() {
    printAdjMatrix(graph);
    cout << "BFS: ";
    BFS(0); // start from node 1
    cout << endl;

    bool visited[N] = {false};
    cout << "DFS: ";
    DFS(0, visited);
}
