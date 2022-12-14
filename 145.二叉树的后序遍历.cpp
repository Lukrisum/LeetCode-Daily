/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    postorder(root->left);
    postorder(root->right);
    res.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root)
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
      root = nodeSt.top();
      nodeSt.pop();

      res.push_back(root->val);

      if (root->left)
        nodeSt.push(root->left);
      if (root->right)
        nodeSt.push(root->right);
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
// @lc code=end
