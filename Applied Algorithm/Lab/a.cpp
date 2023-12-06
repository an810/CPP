#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    set<vector<int>> s; 
    vector<int> x = {1,2,3};
    vector<int> y = {1,3,2};
    sort(y.begin(), y.end());
    s.insert(x);
    s.insert(y);
    for (auto i : s) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}