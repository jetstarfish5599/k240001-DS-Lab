#include <iostream>
#include <string>

using namespace std;

#define MAX_NODES 20
#define INF 999999

class Graph {
private:
    int adjMatrix[MAX_NODES][MAX_NODES]; //Stores weights
    string names[MAX_NODES];             //Maps index -> name
    int nodeCount;

    //Find index or add it if new
    int getIndex(string name) {
        // Search if name exists
        for (int i = 0; i < nodeCount; i++) {
            if (names[i] == name) return i;
        }
        //add if not found
        names[nodeCount] = name;
        nodeCount++;
        return nodeCount - 1;
    }

    //Find index 
    int searchIndex(string name) {
        for (int i = 0; i < nodeCount; i++) {
            if (names[i] == name) return i;
        }
        return -1;
    }

public:
    Graph() {
        nodeCount = 0;
        //Initial matrix 0
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                adjMatrix[i][j] = 0; 
            }
        }
    }

    void addEdge(string uStr, string vStr, int w) {
        int u = getIndex(uStr);
        int v = getIndex(vStr);

        //Undirected Graph
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    void dijkstra(string srcStr, string targetStr) {
        int startNode = searchIndex(srcStr);
        int endNode = searchIndex(targetStr);

        if (startNode == -1 || endNode == -1) {
            cout << "Invalid start or end node.\n";
            return;
        }

        //Arr for Dijkstra
        int dist[MAX_NODES];
        bool visited[MAX_NODES];
        int parent[MAX_NODES]; //reconstruct path

        // Initialize
        for (int i = 0; i < MAX_NODES; i++) {
            dist[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[startNode] = 0;

        //all nodes
        for (int count = 0; count < nodeCount; count++) {
            
            //first mini distance
            int u = -1;
            int minVal = INF;

            for (int i = 0; i < nodeCount; i++) {
                if (!visited[i] && dist[i] < minVal) {
                    minVal = dist[i];
                    u = i;
                }
            }

            //no more nodes or reached target
            if (u == -1 || dist[u] == INF) break;
            
            visited[u] = true;
            if (u == endNode) break; //stop if target reached

            //Relax edges (check neighbors)
            for (int v = 0; v < nodeCount; v++) {
                //Check for edges
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int alt = dist[u] + adjMatrix[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        parent[v] = u;
                    }
                }
            }
        }

        //Output
        if (dist[endNode] == INF) {
            cout << "No path exists between " << srcStr << " and " << targetStr << endl;
        } else {
            //Reconstruct using array
            int path[MAX_NODES];
            int pathIdx = 0;
            int curr = endNode;

            while (curr != -1) {
                path[pathIdx++] = curr;
                curr = parent[curr];
            }

            cout << "Shortest Path: ";
            //Print in rev
            for (int i = pathIdx - 1; i >= 0; i--) {
                cout << names[path[i]];
                if (i > 0) cout << " -> ";
            }
            cout << endl;
            cout << "Total Cost: " << dist[endNode] << endl;
        }
    }
};

int main() {
    Graph g;
    
    //graph
    g.addEdge("B", "A", 4);
    g.addEdge("A", "D", 8);
    g.addEdge("B", "C", 9);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "E", 14);
    g.addEdge("D", "F", 4);
    g.addEdge("E", "F", 3);

    //Algorithm
    g.dijkstra("B", "E");

    return 0;
}