// link: https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int weights[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    int min_diff = pow(10, 9); // initialize to large value
    for (int i = 0; i < pow(2, n); i++) { // loop through all possible subsets
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) { // check which apples belong to which subset
            if (i & (1 << j)) {
                sum1 += weights[j];
            } else {
                sum2 += weights[j];
            }
        }
        min_diff = min(min_diff, abs(sum1 - sum2)); // update minimum difference
    }
    
    cout << min_diff << endl;
    return 0;
}