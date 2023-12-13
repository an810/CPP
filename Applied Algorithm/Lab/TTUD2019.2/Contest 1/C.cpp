#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll res = (a % MOD + b % MOD) % MOD;
    cout << res;
    return 0;
}