// link: https://www.spoj.com/problems/ELEVTRBL/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1000007;

int f, s, g, u, d;
int res[maxN];
bool visit[maxN];

void bfs(int up, int down) {
    fill_n(res, f+1, 0);
    fill_n(visit, f+1, false);

    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == g) return;

        for (int y : {x + u, x - d}) {
            if (y > f || y < 1) continue;

            if (!visit[y]) {
                visit[y]  = true;
                res[y] = res[x] + 1;
                q.push(y);
            }
        }
    }
    res[g] = -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    bfs(u, d);
    if (res[g] != -1) cout << res[g];
    else cout << "use the stairs";
    return 0;
}