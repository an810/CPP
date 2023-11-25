#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
int t;
pair<int,int> x[N];


bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void input() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x[i].first >> x[i].second;
    }
}
void solve() {
    int end = -1;
    int count = 0;
    sort(x, x+t, cmp);
    for (int idx = 0; idx < t; idx++) {
        if (x[idx].first > end) {
            count++;
            end = x[idx].second;
        } 
    }
    cout << count;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    input();
    solve();
    return 0;
}