#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100000

int n, l1, l2;
int a[MAX+1];
int dp[MAX+1];

void input() {
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (i < l1) dp[i] = a[i];
        else if (i <= l2 && i >= l1) {
            int max1 = -1, max2 = -1;
            for (int j = 1; j <= i; j++) 
                max1 = max(max1, dp[j]);
            for (int j = i-l1; j <= i; j++)
                max2 = max(max2, dp[j]);
            dp[i] = max(max1, max2 + a[i]);
        }
        else {
            int max1 = -1, max2 = -1;
            for (int j = i-1; j <= i; j++) 
                max1 = max(max1, dp[j]);
            for (int j = i-l2; j <= i-l1; j++)
                max2 = max(max2, dp[j]);
            dp[i] = max(max1, max2 + a[i]);
        } 
        // else if (i < l2) dp[i] = a[i] + dp[i-l1];
        // else dp[i] = a[i] + max(dp[i-l1], dp[i-l2]);
    }
    int res = -1;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    solve();
    return 0;
}