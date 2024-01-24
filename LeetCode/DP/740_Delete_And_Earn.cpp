#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for (int i=0; i<n; i++) 
            m[nums[i]] += nums[i];
        int dp[2] = {0};
        int prev = -1;
        for (auto v : m) {
            int key = v.first, val = v.second;
            int temp = dp[0];
            if ( key - 1 == prev) {
                dp[0] = max(dp[0], dp[1]);
                dp[1] = temp + val;
                prev = key;
                continue;
            }
            dp[0] = max(dp[0], dp[1]);
            dp[1] = val + max(temp, dp[1]);
            prev = key;
        }
        return max(dp[1], dp[0]);
    }
};