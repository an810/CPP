// link: https://cses.fi/problemset/task/1622
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << ans.size() << "\n";
    for (string a : ans) {
        cout << a << "\n";
    }
    return 0;
}