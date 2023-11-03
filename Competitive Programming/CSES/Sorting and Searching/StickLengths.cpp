// link: https://cses.fi/problemset/task/1074
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5;
int n, p[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int x = p[n/2];
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += abs(p[i]- x);
    }
    cout << ans;
    return 0;
}