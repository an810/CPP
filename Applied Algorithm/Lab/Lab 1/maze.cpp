#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> ii;
const int N = 999 + 100;
int n, m, r, c, a[N][N], d[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
queue<ii> q;

int solve() {
    q.push(ii(r, c));
    d[r][c] = 0; 
    a[r][c] = 1;
    while (!q.empty())
    {
        ii u = q.front(); q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x = u.first + dx[i], y = u.second + dy[i];
            if (x < 1 || x > m || y < 1 || y > n) return d[u.first][u.second] + 1;
            if (a[x][y] != 1) {
                a[x][y] = 1;
                d[x][y] = d[u.first][u.second] + 1;
                q.push(ii(x, y));
            }       
        }
    }
    return -1;
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n >> r >> c;
    for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) cin >> a[i][j];
    cout << solve() << endl;
    return 0;
}