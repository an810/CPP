#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 100007

int n, m, components = 0;
bool visited[maxN];
vector<int> g[maxN];

void bfs(int s) {
    ++components;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visited[v]) {
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
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill_n(visited, n+1, false);
    for (int i = 1; i<= n; i++) {
        if (!visited[i]) 
            bfs(i);
    }
    cout << components;
    return 0;
}

/*
    test case:
    7 6
    1 2
    1 3
    2 3
    5 6
    6 7
    5 7
    -> 3
*/
