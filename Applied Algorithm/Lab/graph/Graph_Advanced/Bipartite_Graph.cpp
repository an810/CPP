#include<bits/stdc++.h>
using namespace std;

#define ll long long

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

vector<int> adj[1000];
vector<int> side(1001, -1);
bool is_bipartite = true;
void Check_Bipartite(int u) {
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (side[v] == -1) {
            side[v] = 1 - side[u];
            Check_Bipartite(v);
        } else if (side[u] == side[v]) {
            is_bipartite = false;
        }
    }
}

int main()
{
    int n;
    for (int u=0; u<n; u++) {
        if (side[u] == -1) {
            side[u] = 0;
            Check_Bipartite(u);
        }
    }
    return 0;
}