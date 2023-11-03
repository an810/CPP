#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e3+1;
int a[N][N];
int n, m;
int ans;
ll h[N];
stack<ll> S;
vector<ll> V;
ll L[N], R[N];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
}

ll compute() {
    h[0] = -1; h[m+1] = -1; V.clear();
    for (int i = 1; i <= m+1; i++) {
        while (!V.empty() && h[i] < h[V[V.size()-1]]) {
            R[V[V.size()-1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    for (int i = m; i >= 0; i--) {
        while (!V.empty() && h[i] < h[V[V.size()-1]]) {
            L[V[V.size()-1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    unsigned ll ans = 0;
    for (int i = 1; i <= m; i++) {
        unsigned ll tmp = (R[i] - L[i] - 1) * h[i];
        ans = max(ans, tmp);
    }
    return ans;
}

void solve() {
    ll ans = 0;
    for (int i = 1; i <= m; i++) h[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m+1; j++) {
            if (a[i][j] == 0) h[j] = 0;
            else h[j]++;
        }
        ans = max(ans, compute());
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    solve();
    return 0;
}