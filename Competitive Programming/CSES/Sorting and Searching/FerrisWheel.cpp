// link: https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5;
int n, x, a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans =0; 
    for(int i=0, j=n-1; i<j; ) {
        while (i<j && a[i]+a[j] >x)
            j--;
        if(i>=j)
            break;
        ans++; i++; j--;
    }
    cout << n - ans;
    return 0;
}