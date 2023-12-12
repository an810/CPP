#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 1000

const ll MOD = 1e9+7;
int dp[mxN][mxN];

// (= +1, )= -1, ()==
// dp[i][j] xét phần tử i có tổng điểm j 
int solve(string s) {
    if (s[0] == ')') return 0;
    if (s[0] == '(') dp[0][1] = 1;
    if (s[0] == '?') dp[0][1] = 1;
    for (int i=1; i<s.length(); i++) {
        for (int j=0; j<= i; j++) {
            if (s[i] == '(') {
                if(j>0) dp[i][j] += dp[i-1][j-1] % MOD;
            }
            if (s[i] == ')') 
                dp[i][j] += dp[i-1][j+1] % MOD;
            if (s[i] == '?') {
                dp[i][j] += dp[i-1][j+1] % MOD;
                if (j>0) dp[i][j] += dp[i-1][j-1] % MOD;
            }
        }
    }
    return dp[s.length()-1][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    string s; 
    // freopen("../../test.txt", "r", stdin);
    cin >> s;
    cout << solve(s);
    return 0;
}