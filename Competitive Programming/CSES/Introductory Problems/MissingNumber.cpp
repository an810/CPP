// link: https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, s = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        s += a;
    }
    cout << n * (n + 1) / 2 - s;
    return 0;
}