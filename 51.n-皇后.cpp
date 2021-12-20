/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
    int n;
    vector<int> board;
    vector<vector<string>> ans;

public:
    bool valid(int row, int column)
    {
        int prevRow = row - 1, leftUp = column - 1, rightUp = column + 1;
        while (prevRow >= 0)
        {
            if (board[prevRow] == column)
                return false;
            if (leftUp > -1 && board[prevRow] == leftUp--)
                return false;
            if (rightUp < n && board[prevRow] == rightUp++)
                return false;
            --prevRow;
        }
        return true;
    }
    void dfs(int row)
    {
        if (row == n)
        {
            auto b = vector<string>(n, string(n, '.'));
            for (int r = 0; r < n; ++r)
            {
                b[r][board[r]] = 'Q';
            }
            ans.emplace_back(move(b));
            return;
        }
        for (int column = 0; column < n; ++column)
        {
            if (valid(row, column))
            {
                board[row] = column;
                dfs(row + 1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        board = vector<int>(n);
        dfs(0);
        return move(ans);
    }
};
// @lc code=end