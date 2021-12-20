/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &dp)
    {
        int n1 = dp.size() - 1,n2,row,nextRow,column;
        for (row = dp.size() - 2; row >= 0; --row)
        {
            nextRow = row + 1;
            n2 = dp[nextRow].size() - 1;

            for (column = 0; column < n2; ++column)
            {
                dp[row][column] = min(dp[nextRow][column], dp[nextRow][column + 1]) + dp[row][column];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
