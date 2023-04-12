// link: https://codeforces.com/group/cGzZeXNyzp/contest/437241/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string res = "";
        while(n > 0)
        {
            char c = (n%2) + '0';
            res += c ;
            n/=2;
        }
        reverse(res.begin(),res.end());
        cout << res << '\n';
    }
    return 0;
}