// link: https://luyencode.net/problem/lake?fbclid=IwAR0sdIfj3tW5o9QU1rnzwSlVdsJqm_ngzSumQSmKhyl5_aj6f_bVBq8fsNk
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 101;
int m,n,k;
int a[N][N];
bool visited[N][N];

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

int bfs(int )

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++) {
        fill_n(visited[i], n+1, false);
        fill_n(a[i], n+1, 0);
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    return 0;
}