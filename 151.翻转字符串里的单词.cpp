/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;

        while (s[l] == ' ')
            ++l;
        while (s[r] == ' ')
            --r;
        string ans(r - l + 1, 0);
        int cur = 0;
        while (l <= r)
        {
            
        }
        return move(ans);
    }
};
// @lc code=end
