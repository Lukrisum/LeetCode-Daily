/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
  bool dfs(TreeNode *leftNode, TreeNode *rightNode)
  {

    if (leftNode == nullptr && rightNode == nullptr)
    {
      return true;
    }

    if (leftNode == nullptr || rightNode == nullptr)
    {
      return false;
    }

    if (leftNode->val != rightNode->val)
    {
      return false;
    }

    return dfs(leftNode->left, rightNode->right)&dfs(leftNode->right, rightNode->left);
  }

  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }
    return dfs(root->left, root->right);
  }
};

// @lc code=end
