// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/F

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t) {
        int n; cin >> n;
        int max_candies = 0;
        ll alice = 0, bob = 0;
        vector<int> weights;
        for(int i=0; i<n; i++) {
            int weight; cin >> weight;
            weights.push_back(weight);
        }
        int left = 0, right = n-1;
        while (left <= right) {
            if (alice <= bob) {
                alice += weights[left];
                left++;
            } else {
                bob += weights[right];
                right--;
            }
            if (alice == bob) {
                max_candies = max(max_candies, left + (n - 1 - right));
            }
        }
        cout << max_candies << "\n";
        t--;
    }
    return 0;
}         