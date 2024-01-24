#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        if (obstacleGrid[0][0] == 1) return 0;
        dp[1][1] = 1;
        for (int i=0; i<=m; i++) 
            dp[i][0] = 0;
        for (int i=0; i<=n; i++) 
            dp[0][i] = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i==1 && j==1) continue;
                if (obstacleGrid[i-1][j-1] == 1 || (dp[i-1][j] == INT_MIN && dp[i][j-1] == INT_MIN)) {
                    dp[i][j] = INT_MIN;
                    continue;
                }
                if (dp[i-1][j] == INT_MIN) {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                if (dp[i][j-1] == INT_MIN) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n] != INT_MIN ? dp[m][n] : 0;
    }
};