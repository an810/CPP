// link: https://codeforces.com/group/cGzZeXNyzp/contest/436634/problem/B
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t) {
        int n, cur = 0;
        cin >> n;
        vector<int> res;
        queue<int> s;
        for (int i=0; i<n; i++)  {
            int start; cin >> start;
            s.push(start);
        }
        for (int i=0; i<n; i++) {
            int end; cin >> end;
            int start = s.front();
            s.pop();
            if (cur <= start) {
                res.push_back(end - start);
                cur = end;
            } else {
                res.push_back(end - cur);
                cur = end;
            }
        }
        for (int i=0; i<n; i++) 
            cout << res[i] << " ";
        cout << "\n";
        t--;
    }
    return 0;
}