#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1003;
int n;
int a[maxn];

int solve(int a[]) {
    int cnt = 0;
    int i = 1;
    while (i <= n) {
        if (a[i+2] - a[i] <= 10) {
            cnt++; i+=3;
            continue;
        }
        if (a[i+1] - a[i] <= 20) {
            cnt++; i+=2;
            continue;
        }
        cnt++; i++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    a[n+1] = a[n+2] = a[n+3] = 2000;
    sort(a+1, a+n+1);

    // for (int i=1; i<=n; i++)
    //     cout << a[i] << " ";
    cout << solve(a);
    return 0;
}