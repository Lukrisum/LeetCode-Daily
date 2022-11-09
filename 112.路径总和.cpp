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
  int target;
  int sum = 0;
  bool res = false;

  void dfs(TreeNode *root)
  {

    if (root->left == nullptr && root->right == nullptr)
    {
      sum += root->val;

      cout << sum << endl;

      if (sum == target)
      {
        res = true;
      }

      sum -= root->val;
      return;
    }

    if (root->left)
    {
      sum += root->val;
      dfs(root->left);
      sum -= root->val;
    }

    if (root->right)
    {
      sum += root->val;
      dfs(root->right);
      sum -= root->val;
    }
  }

  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (root == nullptr)
    {
      return false;
    }

    target = targetSum;

    dfs(root);

    return res;
  }
};

// @lc code=end