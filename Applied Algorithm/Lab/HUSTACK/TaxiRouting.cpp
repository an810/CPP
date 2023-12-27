#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 12

int n;
int x[2*N], c[2*N+1][2*N+1];
int mark[N];
int cmin = INT_MAX;
int ans = INT_MAX;
int sum = 0;

void input() {
    // freopen("../test.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=2*n; j++) {
            cin >> c[i][j];    
            cmin = min(cmin, c[i][j]);
        }
    }
        
}


void solve(int k) {
    for (int v=1; v<=n; v++) {
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            if (k==1) {
                sum += c[0][x[k]] + c[x[k]][x[k]+n];
            } else {
                sum += c[x[k-1]+n][x[k]] + c[x[k]][x[k]+n];
            }
            if (k==n) {
                sum += c[x[k]+n][0];
                ans = min(ans, sum);
            }
            else {
                if (sum + cmin* (2*(n-k) + 1) < ans) 
                    solve(k+1);
            }
            if (k==1) {
                sum -= c[0][x[k]] + c[x[k]][x[k]+n];
            } else {
                sum -= c[x[k-1]+n][x[k]] + c[x[k]][x[k]+n];
                if (k==n) sum-= c[x[k]+n][0];
            }
            mark[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    solve(1);
    cout << ans;
    return 0;
}