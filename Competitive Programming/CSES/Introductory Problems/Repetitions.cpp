// link: https://cses.fi/problemset/task/1069
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
    char l = 'A';
    int ans = 1, c = 0;
    for (char d : s)
    {
        if (l == d)
        {
            c++;
            ans = max(ans, c);
        }
        else
        {
            l = d;
            c = 1;
        }
    }
    cout << ans;
    return 0;
}