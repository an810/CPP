#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 1000006

const ll MOD = 1e9+7;

int n;
ll a[mxN];
ll sum = 0;

ll compute(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum = compute(sum, a[i]);
    }
    cout << sum;
    return 0;
}