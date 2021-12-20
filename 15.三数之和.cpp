/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size(), t, l, r, s;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            t = -nums[i];
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                s = nums[l] + nums[r];
                if (s > t)
                    --r;
                else if (s < t)
                    ++l;
                else
                {
                    ans.emplace_back(vector{nums[i], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == ans.back()[1])
                        ++l;
                    while (l < r && nums[r] == ans.back()[2])
                        --r;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i;
        }

        return move(ans);
    }
};
// @lc code=end
