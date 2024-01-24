#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5001;
int n, k;
pair <int, int> a[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1, cmp);
    
    return 0;
}