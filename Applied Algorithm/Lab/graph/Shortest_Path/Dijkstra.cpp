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

// Dijkstra 

const int INF = INT_MIN;
vector<edge> adj[100];
vector<int> dist(100, INF);

void Dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    PQ.push(make_pair(dist[start], start));
    while (!PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();
        for (int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].weight;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                PQ.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    
    
    return 0;
}