// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/E

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
        map<int,int> maxPosition; //Keep track of the max position of b
        map<int,int> minPosition; //Keep track of the min position of a

        for (int i = 0; i < n; i++)
        {
            int u;
            cin >> u;
            if (minPosition.find(u) == minPosition.end())
            {
                minPosition[u] = i;
            }
            maxPosition[u] = i;
        }

        while (k--)
        {
            int a; cin >> a;
            int b; cin >> b;

            if (minPosition.find(a) != minPosition.end() && maxPosition.find(b) != maxPosition.end()
                && minPosition[a] < maxPosition[b])
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}