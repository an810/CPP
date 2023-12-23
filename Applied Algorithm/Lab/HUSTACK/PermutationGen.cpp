#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 21

int n;
int x[N];
int mark[N] = {0};

void solution() {
    for (int i=1; i<=n; i++)
        cout << x[i];
    cout << "\n";
}

void solve(int k) {
    for (int v=1; v<=n; v++) {
        if (!mark[v]) {
            x[k] = v;
            mark[v] = 1;
            if (k==n) solution();
            else solve(k+1);
            mark[v] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n; solve(1);
    return 0;
}