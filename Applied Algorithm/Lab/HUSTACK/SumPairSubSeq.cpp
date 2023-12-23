#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000006

int n, Q, M;
int a[N];
unordered_map<int, int> appear;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> M;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        if (appear.find(M-a[i]) != appear.end())
            Q += appear[M-a[i]];
        appear[a[i]]++;
    }
    cout << Q;
    return 0;
}