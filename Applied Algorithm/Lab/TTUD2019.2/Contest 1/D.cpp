#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    ll res = 1;
    for (int i=0; i<b; i++) {
        res = ((res % MOD) * (a % MOD)) % MOD;
    }
    cout << res;
    return 0;
}