#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 1000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    int index = 1;
    while (t--) {
        int n; cin >> n;
        int x[mxN], y[mxN];
        for (int i=0; i<n; i++) cin >> x[i];
        for (int i=0; i<n; i++) cin >> y[i];
        sort(x,x+n);
        sort(y,y+n, greater<int>());
        ll sum=0;
        for (int i=0; i<n; i++) sum+=x[i]*y[i];
        cout << "Case #" << index << ": " << sum << "\n";
        index++;
    }
    return 0;
}