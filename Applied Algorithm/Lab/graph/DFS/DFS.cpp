#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[1001];
vector<bool> visited(1001, false);
vector<bool> marked(10001, false);

void DFS(int u) {
    if (marked[u])
        return;
    marked[u] = true;
    visited[u] = true;
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        visited[v] = true;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}