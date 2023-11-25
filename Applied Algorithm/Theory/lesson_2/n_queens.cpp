#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 8

int n;
int x[N];

int check(int v, int k) {
    for (int i = 1; i<=k-1; i++) {
        if (x[i] == v) return 0;
        if (x[i]+i == v+k) return 0;
        if (x[i]-i == v-k) return 0;
    }
    return 1;
}

void solution() {
    for(int i=1; i<= n; i++) cout << x[i] << ' ';
    cout << '\n';
}

void TRY(int k) {
    for(int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) solution();
            else TRY(k+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    TRY(1);
    return 0;
}