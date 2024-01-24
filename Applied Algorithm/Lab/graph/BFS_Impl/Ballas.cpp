// link: https://lqdoj.edu.vn/problem/cjpaysballas
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1000006;

int N, M, s, t;
vector<int> g[maxN];
bool visited[maxN];
int par[maxN]; // luu lai vet duong di

void bfs(int start) {
    fill_n(visited, N+1, false);
    fill_n(par, N+1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();        
        for (auto v : g[u]) {
            if (!visited[v]) {
                par[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M >> s >> t;
    while (M--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    for (int i=1; i<=N; i++) {
        sort(g[i].begin(), g[i].end());
    }
    bfs(s);
    vector <int> path;
    for (int v = t; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    
    for (auto v : path) cout << v << ' ';
    return 0;
}