#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    int u, v, weight;
    edge(int _u, int _v, int _w) {
        u =_u;
        v = _v;
        weight = _w;
    }
};

const int INF = INT_MIN;
vector<edge> adj[100];
vector<int> dist(100, INF);

void BellmanFord(int n, int start) {
    dist[start] = 0;
    for (int i=1; i<n-1; i++) {
        for (int u=1; u<=n; u++) {
            for (int j=0; j<adj[u].size(); j++) {
                int v = adj[u][j].v;
                int w = adj[u][j].weight;
                dist[v] = min(dist[v], w + dist[u]);
            }
        }
    }
}

int main()
{
   
    
    return 0;
}