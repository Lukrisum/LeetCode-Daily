/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> res;

  void postorder(TreeNode *root)
  {

    if (root == nullptr)
    {
      return;
    }
    res.push_back(root->val);
    postorder(root->left);
    postorder(root->right);
  }

  vector<int> preorderTraversal(TreeNode *root)
  {
    // 递归
    // postorder(root);

    // 非递归
    if (root == nullptr)
    {
      return res;
    }

    stack<TreeNode *> nodeSt;
    nodeSt.push(root);
    
    while (!nodeSt.empty())
    {
      TreeNode *cur = nodeSt.top();
      nodeSt.pop();
      res.push_back(cur->val);

      if (cur->right != nullptr)
      {
        nodeSt.push(cur->right);
      }

      if (cur->left != nullptr)
      {
        nodeSt.push(cur->left);
      }
    }
    return res;
  }
};

// @lc code=end
