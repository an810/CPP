// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/G

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t) {
        int n, k; cin >> n >> k;
        vector<ll> list(n);
        unordered_map<ll, bool> exist;
        for (int i=0; i<n; i++) {
            cin >> list[i];
            exist[list[i]] = true;
        }
        int check = 0;
        for (int i=0; i<n; i++) {
            if (exist[list[i] - k]) {
                check = 1;
                break;
            }
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
        t--;
    }
    return 0;
}