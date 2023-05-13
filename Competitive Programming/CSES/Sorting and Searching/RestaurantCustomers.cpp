// link: https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n ;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    // for (int i=0; i<n; i++) {
    //     cout << a[i].first << " " << a[i].second << "\n";
    // }
    int ans = 1;
    for (int i=0; i<n-1; i++) {
        int cnt = 1, j=i+1;
        while (a[i].second > a[j].first)
            j++, cnt++;
        ans = max(ans, cnt);
        // cout << cnt << "\n";
    }
    cout << ans;
    return 0;
}