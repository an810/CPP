#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 1000006

int n;
int a[mxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int l_foot = 0, r_foot=0;
    int head = 0;
    int height=0, deepth = 0;
    for (int i=1; i<n; i++) {
        if (a[i] > a[i-1]) {
            head = i;
            if (r_foot == i-1) l_foot = i-1;
        }
        if (a[i] < a[i-1]) r_foot = i;
        if (a[i] == a[i-1]) r_foot = l_foot = head = i;
        if (l_foot < head && head < r_foot) height = max(height, min(r_foot-head, head-l_foot));
    }
    for (int i=1; i<n; i++) {
        if (a[i] < a[i-1]) {
            head = i;
            if (r_foot == i-1) l_foot = i-1;
        }
        if (a[i] > a[i-1]) r_foot = i;
        if (a[i] == a[i-1]) r_foot = l_foot = head = i;
        if (l_foot < head && head < r_foot) deepth = max(deepth, min(r_foot-head, head-l_foot));
    }

    cout<<height << " " << deepth;
    return 0;
}