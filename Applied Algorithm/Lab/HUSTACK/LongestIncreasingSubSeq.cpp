#include <iostream>
using namespace std;

#define ll long long
#define mxN 100005

int n;
int a[mxN];
int dp[mxN];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    // freopen("../test.txt", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}
