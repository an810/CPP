// link: https://vnoi.info/wiki/algo/graph-theory/breadth-first-search.md#thu%E1%BA%ADt-to%C3%A1n
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 210;

int n;
int d[maxN];
vector<int> g[maxN];
bool visit[maxN];

int bfs(int s) {
    fill_n(d, n+1, 0);
    fill_n(visit, n+1, false);

    queue<int> q;
    q.push(s);
    visit[s] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == s) return d[u] + 1;
        for (auto v : g[u]) {
            if (!visit[v]) {
                d[v] = d[u] + 1;
                visit[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int h; cin >> h;
            if (h) g[i].push_back(j);
        }
    }
    for (int i=1; i<=n; i++) {
        int ans = bfs(i);
        if (ans) cout << ans << '\n';
        else cout << "NO WAY\n";
    }
    return 0;
}