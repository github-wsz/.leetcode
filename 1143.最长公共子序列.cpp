/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mem;
    int dfs(string &s1, string &s2, int a, int b, int &ans, int curLen)
    {
        if (s1.size() == a || s2.size() == b)
        {
            if (curLen > ans)
                ans = curLen;
            return curLen;
        }

        if (!mem[a][b])
        {
            if (s1[a] == s2[b])
                mem[a + 1][b + 1] = dfs(s1, s2, a + 1, b + 1, ans, curLen + 1);
            else
            {
                mem[a + 1][b] = dfs(s1, s2, a + 1, b, ans, curLen);
                mem[a][b + 1] = dfs(s1, s2, a, b + 1, ans, curLen);
            }
        }

        return mem[a][b];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int ans = 0;
        mem = vector<vector<int>>(text1.size(), vector<int>(text2.size(), 0));
        dfs(text1, text2, 0, 0, ans, 0);
        return ans;
    }
};
// @lc code=end
