#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 100005

int n, Q, k;
int a[mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    int sum = 0;
    for (int i=1; i<=k; i++) sum += a[i];
    if (sum % 2 == 0) Q++;
    for (int i=k+1; i<=n; i++) {
        sum = sum - a[i-k] + a[i];
        if (sum % 2 == 0)
            Q++;
    }
    cout << Q;
    return 0;
}