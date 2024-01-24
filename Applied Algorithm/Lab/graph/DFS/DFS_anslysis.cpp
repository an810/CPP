#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int n = 1001;
vector<int> adj[n];
vector<int> low(n), num(n, -1);
int curnum = 0;

void DFS(int u, int p) {
    low[u] = num[u] = ++curnum;
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        if (num[v] == -1) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}
// Goi DFS(u, -1) voi moi u chua duoc tham (num[u] == -1)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}