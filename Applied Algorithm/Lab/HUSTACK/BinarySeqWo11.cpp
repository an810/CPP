#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 21
int n;
int x[MAX];

void solution() {
    for (int i=1; i<=n; i++) 
        cout << x[i];
    cout << "\n";
}

int check(int k, int v) {
    if (k==1) return 1;
    if (v==1 && x[k-1]==1) return 0;
    return 1;
}

void solve(int k) {
    for (int v = 0; v<=1; v++) {
        if (check(k,v))  {
            x[k] = v;
            if (k==n) solution();
            else solve(k+1);
        }
        else continue; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    solve(1);
    return 0;
}