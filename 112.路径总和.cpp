/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
  bool dfs(TreeNode *root, int sum, int target)
  {
    if (root == nullptr)
    {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
      sum += root->val;
      if (sum != target)
      {
        return false;
      }
      return true;
    }

    bool leftRes = false;
    bool rightRes = false;

    if (root->left)
    {
      leftRes = dfs(root->left, sum + root->val, target);
    }

    if (root->right)
    {
      rightRes = dfs(root->right, sum + root->val, target);
    }

    return leftRes || rightRes;
  }

  bool hasPathSum(TreeNode *root, int targetSum)
  {
    return dfs(root, 0, targetSum);
  }
};

// @lc code=end