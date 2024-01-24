#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 100

int n; // number of vertices
int d[maxN], par[maxN]; // d saves distance from origin to all vertices, par saves path 
bool visited[maxN];
vector<int> g[maxN];

void bfs(int s) { 
    fill_n(d, n+1, 0);
    fill_n(par, n+1, -1);
    fill_n(visited, n+1, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
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
    
    return 0;
}

