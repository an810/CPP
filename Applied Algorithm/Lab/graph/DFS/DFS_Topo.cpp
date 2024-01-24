#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[10001];
vector<bool> visited(1001, false);
vector<int> order;

void Topo_Sort(int u) {
    if (visited[u]) return;

    visited[u] = true;
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        Topo_Sort(v);
    }
    order.push_back(u);
}

// Goi Topo_Sort(u) voi moi dinh u chua duoc tham

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}