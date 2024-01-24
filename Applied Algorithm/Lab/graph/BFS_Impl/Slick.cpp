// link: https://www.spoj.com/problems/UCV2013H/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxN 300

bool visited[maxN][maxN];
int n, m;
bool a[maxN][maxN];
vector<int> slicks;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void reset() {
    slicks.clear();
    for (int i = 1; i <= n; i++) 
        fill_n(visited[i], m+1, false);
}

int bfs(int sx, int sy) {
    int sizeSlicks = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (u > n || u < 1) continue;
            if (v > m || v < 1) continue;

            if (a[u][v] && !visited[u][v]) {
                ++sizeSlicks;
                visited[u][v] = true;
                q.push({u, v});
            }
        }
    }
    return sizeSlicks;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    while (cin >> n >> m) {
        if (!n && !m) return 0;

        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                if (a[i][j] && !visited[i][j])
                    slicks.push_back(bfs(i,j));
        cout << slicks.size() << '\n';

        sort(slicks.begin(), slicks.end());
        slicks.push_back(1e9);
        int number = 0, pre = slicks[0];
        for (auto v : slicks)
            if (v != pre) {
                cout << pre << ' ' << number << '\n';
                pre = v;
                number = 1;
            }
            else ++number;

        reset();   
    }
    return 0;
}