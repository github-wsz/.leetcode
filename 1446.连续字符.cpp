/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dfs(string &s, int len){
        
    }
    int maxPower(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 1);
        --n;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == s[i + 1])
                dp[i + 1] = dp[i] + 1;
            if (dp[i + 1] > dp[n])
                dp[n] = dp[i + 1];
        }
        return dp[n];
    }
};
// @lc code=end
