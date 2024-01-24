#include <iostream>
#include <vector>
#include <queue>

//MST - Prim

using namespace std;

struct edge
{
    int u, v;
    int weight;

    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<edge> mst(int n, vector<vector<edge>> Adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<edge> res;
    vector<int> iBest_W(n + 1, 1e9), iBest_A(n + 1, -1);
    vector<bool> visited(n + 1, false);  // Track visited vertices
    iBest_W[1] = 0;
    PQ.push({iBest_W[1], 1});

    while (!PQ.empty()) {
        int w = PQ.top().first, v = PQ.top().second;
        PQ.pop();

        if (visited[v]) {
            continue;  // Skip visited vertices
        }

        visited[v] = true;

        if (w != iBest_W[v]) {
            continue;  // Skip outdated entries in the priority queue
        }

        if (iBest_A[v] != -1) {
            res.push_back({iBest_A[v], v, w});
        }

        for (const edge &e : Adj[v]) {
            if (!visited[e.v] && iBest_W[e.v] > e.weight) {
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;
                PQ.push({iBest_W[e.v], e.v});
            }
        }
    }

    return res;
}

int main(void)
{
    // Create a small connected graph with 4 vertices
    int numVertices = 7;
    vector<vector<edge> > adjacencyList(numVertices + 1);  // Vertices are 1-indexed

    // Add edges to the graph
    adjacencyList[1].push_back(edge(1, 2, 7));
    adjacencyList[1].push_back(edge(1, 4, 5));

    adjacencyList[2].push_back(edge(2, 1, 7));
    adjacencyList[2].push_back(edge(2, 3, 8));
    adjacencyList[2].push_back(edge(2, 4, 9));
    adjacencyList[2].push_back(edge(2, 5, 7));

    adjacencyList[3].push_back(edge(3, 2, 8));
    adjacencyList[3].push_back(edge(3, 5, 5));

    adjacencyList[4].push_back(edge(4, 1, 5));
    adjacencyList[4].push_back(edge(4, 2, 9));
    adjacencyList[4].push_back(edge(4, 5, 15));
    adjacencyList[4].push_back(edge(4, 6, 6));

    adjacencyList[5].push_back(edge(5, 2, 7));
    adjacencyList[5].push_back(edge(5, 3, 5));
    adjacencyList[5].push_back(edge(5, 4, 15));
    adjacencyList[5].push_back(edge(5, 6, 8));
    adjacencyList[5].push_back(edge(5, 7, 9));

    adjacencyList[6].push_back(edge(6, 4, 6));
    adjacencyList[6].push_back(edge(6, 5, 8));
    adjacencyList[6].push_back(edge(6, 7, 11));

    adjacencyList[7].push_back(edge(7, 5, 9));
    adjacencyList[7].push_back(edge(7, 6, 11));


    // Find the Minimum Spanning Tree (MST) using Prim's algorithm
    vector<edge> minimumSpanningTree = mst(numVertices, adjacencyList);

    // Display the edges of the Minimum Spanning Tree
    cout << "Edges of the Minimum Spanning Tree (MST):" << endl;
    for (const edge &e : minimumSpanningTree)
    {
        cout << "Edge: " << e.u << " - " << e.v << ", Weight: " << e.weight << endl;
    }

    return 0;
}