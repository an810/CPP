#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    int u, v, weight;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

struct Union_Find {
    vector<int> iParent;
    Union_Find(int n) {
        iParent = vector<int>(n+1);
        for (int i=1; i<=n; i++)
            iParent[i]=i;
    }

    int Find(int x) {
        if (iParent[x] == x) {
            return x;
        } else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }
    void Unite(int x, int y) {
        iParent[Find(x)] = Find(y);
    }
};

bool Edge_Cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

vector<edge> mst(int n, vector<edge> edges) {
    Union_Find UF(n);
    sort(edges.begin(), edges.end(), Edge_Cmp);
    vector<edge> res;
    for (int i=0; i<edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (UF.Find(u) != UF.Find(v)) {
            UF.Unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}

int main()
{
    // Create a small connected graph with 4 vertices
    int numVertices; cin >> numVertices;
    int numEdges; cin >> numEdges;
    vector<edge>  adjacencyList;  // Vertices are 1-indexed
    while (numEdges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyList.push_back(edge(u,v,w));
    }

    // // Add edges to the graph
    // adjacencyList.push_back(edge(1, 2, 7));
    // adjacencyList.push_back(edge(1, 4, 5));

    // adjacencyList.push_back(edge(2, 1, 7));
    // adjacencyList.push_back(edge(2, 3, 8));
    // adjacencyList.push_back(edge(2, 4, 9));
    // adjacencyList.push_back(edge(2, 5, 7));

    // adjacencyList.push_back(edge(3, 2, 8));
    // adjacencyList.push_back(edge(3, 5, 5));

    // adjacencyList.push_back(edge(4, 1, 5));
    // adjacencyList.push_back(edge(4, 2, 9));
    // adjacencyList.push_back(edge(4, 5, 15));
    // adjacencyList.push_back(edge(4, 6, 6));

    // adjacencyList.push_back(edge(5, 2, 7));
    // adjacencyList.push_back(edge(5, 3, 5));
    // adjacencyList.push_back(edge(5, 4, 15));
    // adjacencyList.push_back(edge(5, 6, 8));
    // adjacencyList.push_back(edge(5, 7, 9));

    // adjacencyList.push_back(edge(6, 4, 6));
    // adjacencyList.push_back(edge(6, 5, 8));
    // adjacencyList.push_back(edge(6, 7, 11));

    // adjacencyList.push_back(edge(7, 5, 9));
    // adjacencyList.push_back(edge(7, 6, 11));


    // Find the Minimum Spanning Tree (MST) using Prim's algorithm
    vector<edge> minimumSpanningTree = mst(numVertices, adjacencyList);
   
    // Display the edges of the Minimum Spanning Tree
    // cout << "Edges of the Minimum Spanning Tree (MST):" << endl;
    int ans = 0;
    for (const edge &e : minimumSpanningTree)
    {
        // cout << "Edge: " << e.u << " - " << e.v << ", Weight: " << e.weight << endl;
        ans += e.weight;
    }
    cout << ans;
    return 0;
}