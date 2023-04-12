// link: https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll mx = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > mx)
        {
            mx = max(x, mx);
        }
        else
            ans += mx - x;
    }
    cout << ans;
    return 0;
}