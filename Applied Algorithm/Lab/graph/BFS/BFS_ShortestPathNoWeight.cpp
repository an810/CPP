#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[1001];
vector<int> dist(1001, -1);

void DFS(int start, int end) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = 1 + dist[u];
            }
        }
    }

    cout << dist[end] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}