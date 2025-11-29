#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5; //vertices

class Graph {
private:
    vector<int> adjList[N + 1];
    int adjMatrix[N + 1][N + 1];

public:
    Graph() {
        //initiate adj matrix
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int u, int v) {
        //add to adj list
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        //add to adj matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void displayAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 1; i <= N; i++) {
            cout << i << ": ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void BFS(int start) {
        cout << "\nBFS Traversal: ";
        vector<bool> visited(N + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int v : adjList[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int v : adjList[node]) {
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        cout << "\nDFS Traversal: ";
        vector<bool> visited(N + 1, false);
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g;

    //edges from the diagram
    g.addEdge(1, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(2, 5);
    g.addEdge(5, 3);

    g.displayAdjList();
    g.displayAdjMatrix();

    g.BFS(1);
    g.DFS(1);

    return 0;
}
