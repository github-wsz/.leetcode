/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;
        int hashMap['z' + 1];
        for (auto c : magazine)
            ++hashMap[c];
        for (auto c : ransomNote)
            if (--hashMap[c] < 0)
                return false;
        return true;
    }
}; // @lc code=end
