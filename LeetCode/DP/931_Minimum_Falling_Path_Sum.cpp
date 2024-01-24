#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n+2, 0));
        for (int i=0; i<n; i++) 
            dp[n-1][i+1] = matrix[n-1][i];
        for (int i=0; i<n; i++)
            dp[i][0] = dp[i][n+1] = INT_MAX;
        for (int i=n-2; i>=0; i--) {
            for (int j=1; j<=n; j++) {
                int left = dp[i+1][j-1] == INT_MAX ? INT_MAX : matrix[i][j-1] + dp[i+1][j-1];
                int mid = dp[i+1][j] == INT_MAX ? INT_MAX : matrix[i][j-1] + dp[i+1][j];
                int right = dp[i+1][j+1] == INT_MAX ? INT_MAX : matrix[i][j-1] + dp[i+1][j+1];
                dp[i][j] =  min({left, mid, right});
            }
        }
        int res = INT_MAX;
        for (int i=1; i<=n; i++) 
            res = min(res, dp[0][i]);
        return res;
    }
};