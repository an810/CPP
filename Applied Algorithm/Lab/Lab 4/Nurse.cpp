#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1003

const int MOD = 1e9 + 7;
int N, K1, K2;
int dp[MAX][2];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    // freopen("../test.txt", "r", stdin);
    cin >> N >> K1 >> K2;
    for (int i=0; i<=N; i++) {
        dp[i][0] = 0; 
        dp[i][1] = 0;
    }
    dp[1][0] = dp[0][0] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=K1; j<=K2; j++) {
            if (i-j < 0) break;
            dp[i][0] = dp[i-1][1];
            dp[i][1] += dp[i-j][0] % MOD;
        }
    }
    cout << dp[N][0] + dp[N][1];
    return 0;
}