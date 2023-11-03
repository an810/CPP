// link: https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5;
int n, m, k, a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && b[j] < a[i] - k)
            j++;
        if (j < m && b[j] <= a[i] + k) {
            ans++;j++;
        }
            
    }
    cout << ans;
    return 0;
}