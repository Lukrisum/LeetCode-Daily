/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
  bool isTheSame(TreeNode *left, TreeNode *right)
  {
    if (left == nullptr && right == nullptr)
    {
      return true;
    }

    if (left == nullptr || right == nullptr)
    {
      return false;
    }

    if (left->val != right->val)
    {
      return false;
    }

    return isTheSame(left->left, right->left) && isTheSame(left->right, right->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    bool res = false;

    if (root->val == subRoot->val)
    {
      res = isTheSame(root, subRoot) || res;
    }

    if (root->left)
    {
      res = isSubtree(root->left, subRoot) || res;
    }

    if (root->right)
    {
      res = isSubtree(root->right, subRoot) || res;
    }

    return res;
  }
};

// @lc code=end
