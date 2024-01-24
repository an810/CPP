#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[10001];
vector<bool> visited(10001, false);


void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}