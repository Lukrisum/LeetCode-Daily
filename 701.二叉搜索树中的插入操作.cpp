/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
  void insert(TreeNode *root, int target)
  {

    if (root->val > target)
    {
      if (root->left)
      {
        insert(root->left, target);
      }
      else
      {
        root->left = new TreeNode(target);
      }
    }
    else if (root->val <= target)
    {
      if (root->right)
      {
        insert(root->right, target);
      }
      else
      {
        root->right = new TreeNode(target);
      }
    }
  }

  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (root == nullptr)
    {
      root = new TreeNode(val);
      return root;
    }
    insert(root, val);
    return root;
  }
};

// @lc code=end
