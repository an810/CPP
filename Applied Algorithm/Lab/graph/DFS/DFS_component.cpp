#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adj[1001];
vector<int> component(10001, -1);

void find_component(int cur_comp, int u) {
    if (component[u] != -1)
        return;
    component[u] = cur_comp;

    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        find_component(cur_comp, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    int num_comp = 0;
    for (int u=1; u <= n; u++) {
        if (component[u] == -1) {
            find_component(num_comp, u);
            num_comp++;
        }
    }
    return 0;
}