#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 20

int n, x[N], mark[N];

void solution() {
    for (int i = 1; i <= n; i++) 
        cout << x[i];
    cout << '\n';
}

void TRY(int k) {
    for (int v = 1; v <=n; v++) {
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            if (k==n) solution();
            else TRY(k+1);
            mark[v] = 0;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        mark[i] = 0;
    TRY(1);
    return 0;
}