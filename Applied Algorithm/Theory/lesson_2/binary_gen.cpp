#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 20

int n;
int x[N];

void solution() {
    for(int i = 1; i <= n; i++)
        cout << x[i];
    cout << '\n';
}

void TRY(int k) {
    for (int v = 0; v <= 1; v++) {
        x[k] = v;
        if (k == n) solution();
        else TRY(k+1);
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cin >> n;
    TRY(1);
    return 0;
}