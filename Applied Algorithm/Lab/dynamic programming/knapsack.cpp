#include<bits/stdc++.h>
using namespace std;

#define ll long long2
#define mxN 2003

int s, n;
int w[mxN], v[mxN];
int dp[mxN][mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> s >> n;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
    for (int i =1; i<=n; i++) {
        for (int j=0; j<=s; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][s];
    return 0;
}