// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashTable;
        vector<int> ans;
        int n = nums.size();
        int val;
        for (int i = 0; i < n; i++)
        {
            val = target - nums[i];
            if (hashTable.count(val))
                return {i, hashTable[val]};
            hashTable[nums[i]] = i;
        }
        
        return move(ans);
    }
};
// @lc code=end

