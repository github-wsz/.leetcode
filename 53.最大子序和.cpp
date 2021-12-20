/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // f(i,j) = max(f(i-1,j)+nums[i],f(i,j-1)+nums[j],f(i-1,j-1)+nums[i]+nums[j])
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        return dp[0][n - 1];
    }
};
// @lc code=end
