/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream in(s);
        ostringstream out;
        string word;
        while(!(in>>word).eof() && k){
            if (k)
                out << word << " ";
            else
                out << word;
            --k;
        }
        
        return out.str();
    }
};
// @lc code=end

