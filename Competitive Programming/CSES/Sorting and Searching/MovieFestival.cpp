// link: https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5;
int n;
array<int, 2> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a, a+n);
    for (int i=0; i<n; i++) {
        cout << a[i][0] << a[i][1];
    }
    int ans = 0, cur = 0;
    for (int i=0; i<n; i++) {
        if (a[i][1] >= cur) {
            ans++; cur = a[i][0];
        }
    }
    cout << ans;
    return 0;
}