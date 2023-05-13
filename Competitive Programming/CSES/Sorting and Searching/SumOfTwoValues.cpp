// link: https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5;
int n, sum;
int a[N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> sum; 
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int l=0, r= n-1, found = 0;
    while (l<=r) {
        if (a[l] + a[r] < sum) 
            l++;
        else if (a[l] + a[r] > sum)
            r--;
        else {
            cout << l << " " << r;
            found = 1;
            return 0;
        }
    }
    if (!found) cout << "IMPOSSIBLE";
    return 0;
}