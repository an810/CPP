#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 1000006

int n;
int a[mxN];
int dp[mxN];
int ans=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    dp[1] = a[1];
    for (int i=2; i<=n; i++) dp[i] = max(a[i], dp[i-1] + a[i]);
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}