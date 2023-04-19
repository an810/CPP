// link: https://cses.fi/problemset/task/1617
#include<bits/stdc++.h>
using namespace std;

#define N 1e9+7
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, s=1; cin >> n;
    for (int i=0; i<n; i++) {
        s = 2 * s % ((int)N);
    }
    cout << s;
    return 0;
}