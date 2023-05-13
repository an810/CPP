// link: https://cses.fi/problemset/task/2183
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5; 
int n, a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) 
        cin >> a[i];
    sort(a, a+n);
    ll ans = 1;
    for (int i=0; i<n; i++) {
        if (a[i] > ans) break;
        ans += a[i];
    }
    cout << ans;
    return 0;
}
