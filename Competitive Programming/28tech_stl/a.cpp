// link:https://codeforces.com/group/cGzZeXNyzp/contest/436634/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int balloons = 0;
        vector<bool> mark(26, false);
        for (char c : s)
        {
            balloons++;
            if (mark[c-'A'] == false)
            {
                balloons++;
                mark[c-'A'] = true;
            } 
        }
        cout << balloons << '\n';
    }
    return 0;
}