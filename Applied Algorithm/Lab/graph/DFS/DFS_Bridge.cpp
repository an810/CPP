#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Mot canh (u, v) la cau khi va chi khi low[v] > num[u]
const int n = 10001;
vector<int> adj[n], low(n), num(n, -1);
int curnum = 0;
vector<pair<int, int>> iiBridges;

void find_bridges(int u, int p) {
    low[u] = num[u] = ++curnum;
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        if (num[v] == -1) {
            find_bridges(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
        if (low[v] > num[u])
            iiBridges.push_back(make_pair(u,v));
    }
}

// goi find_bridges(u, -1) voi moi u chua duoc tham

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}