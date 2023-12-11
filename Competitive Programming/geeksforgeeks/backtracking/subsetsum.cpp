// link: https://www.geeksforgeeks.org/subset-sum-problem/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005

int a[N];
int n, sum;
int flag = 0;
vector<int> subset;

void input() {
    cin >> n >> sum;
    for(int i = 0; i < n; i++) cin >> a[i];
}

void solution() {
    cout << "[";
    for (int i=0; i<subset.size(); i++)
        cout << subset[i] << " ";
    cout << "]\n";
}

void solve(int i, vector<int>&subset, int s) {
    if (s == sum) {
        solution();
        flag = 1;
        return;
    } 
    if (i == n) return;
    if (a[i] + s <= sum ) {
        subset.push_back(a[i]);
        solve(i+1, subset, s+a[i]);
        subset.pop_back();
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    solve(0, subset, 0);
    if (flag == 0) cout << "No solution\n";
    return 0;
}