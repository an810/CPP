// link: https://cses.fi/problemset/task/1621
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    set<int> s;
    for (int i=0; i<n; i++) {
        int x; 
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}