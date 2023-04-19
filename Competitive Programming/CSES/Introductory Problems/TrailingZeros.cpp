// link: https://cses.fi/problemset/task/1618
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n; cin >> n;
    ll ans = 0;
    for (int i=5; i<=n; i*=5) {
        ans += n/i;
    }
    cout << ans;
    return 0;
}