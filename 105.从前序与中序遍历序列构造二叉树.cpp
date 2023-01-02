/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  unordered_map<int, int> mp;
  TreeNode *buildIt(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
  {
    if (pre_left > pre_right || in_left > in_right)
    {
      return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[pre_left]);

    int in_root = mp[preorder[pre_left]];

    int l_len = in_root - in_left;

    root->left = buildIt(preorder, inorder, pre_left + 1, pre_left + l_len, in_left, in_root - 1);
    root->right = buildIt(preorder, inorder, pre_left + l_len + 1, pre_right, in_root + 1, in_right);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int it = 0;
    for (auto &&i : inorder)
    {
      mp[i] = it;
      it++;
    }

    return buildIt(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }
};
// @lc code=end
