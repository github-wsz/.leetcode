/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
#include <bits/stdc++.h>
using namespace std;
class Codec
{
public:
    void dfs(TreeNode *root, ostringstream &builder)
    {
        if (!root)
        {
            builder << "# ";
            return;
        }
        builder << root->val << ' ';
        dfs(root->left, builder);
        dfs(root->right, builder);
    }

    TreeNode *dfs(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;

        auto root = new TreeNode(stoi(val));
        root->left = dfs(in);
        root->right = dfs(in);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream builder;
        dfs(root, builder);
        return builder.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return dfs(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
