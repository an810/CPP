#include<bits/stdc++.h>
using namespace std;

#define ll long long

int x[7], n;
int mark[10];
int ans;

int check(int v, int k) {
    if (mark[v]) return 0;
    if (k<6) return 1;
    return x[0]*100+x[1]*10+x[2] - v*100-62 + x[3]*1000+x[4]*100+x[5]*10+x[2] == n;
}

void solve(int k) {
    for (int v=1; v<=9; v++) {
        if (check(v,k)) {
            x[k] = v;
            mark[v] = 1;
            if (k==6) ans++;
            else solve(k+1);
            mark[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    solve(0);
    cout << ans;
    return 0;
}