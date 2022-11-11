/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
  bool validate(TreeNode *root, long long MIN, long long MAX)
  {
    if (root == nullptr)
    {
      return true;
    }

    if (!(root->val < MAX && root->val > MIN))
    {
      return false;
    }

    return validate(root->left, MIN, root->val) && validate(root->right, root->val, MAX);
  }

  bool isValidBST(TreeNode *root)
  {
    return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
  }
};

// @lc code=end
