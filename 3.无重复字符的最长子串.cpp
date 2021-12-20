/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hashSet;
        int n = s.size();
        int ans = 0, l = -1, r = 0;
        for (int i = 0; i < n; ++i)
        {
            if (l != -1)
                hashSet.erase(s[l]);
            while (r < n && !hashSet.count(s[r]))
            {
                hashSet.insert(s[r]);
                ++r;
            }
            if (hashSet.size() > ans)
                ans = hashSet.size();
            ++l;
        }

        return ans;
    }
};
// @lc code=end
