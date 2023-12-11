#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define el "\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int a[4], sum = 0;
        for (int i = 0; i < 4; i++) cin >> a[i];
        sort(a, a +4);
        if (a[0] < 0) sum += a[0];
        if (a[1] < 0) sum += a[1];
        cout << sum << el;
    }
    return 0;
}