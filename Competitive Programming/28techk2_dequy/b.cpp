// link: https://codeforces.com/group/cGzZeXNyzp/contest/437241/problem/B

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> ans(n);

void Solution() {
    for (int i=0; i<n; i++) cout << ans[i];
    cout << "\n";
}

void Try(int k) {
    for (int i=0; i<n; i++) {
        ans[k] = i;
        if (k ==n-1 ) Solution();
        else Try(k+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) ans.push_back(0);
    Try(0);
    return 0;
}