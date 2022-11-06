/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

  void recursionInOrder(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    recursionInOrder(root->left);
    res.push_back(root->val);
    recursionInOrder(root->right);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    // 递归
    // recursionInOrder(root);

    // 非递归
    stack<TreeNode *> nodeSt;

    while (root != nullptr || !nodeSt.empty())
    {
      /* code */
      while (root != nullptr)
      {
        nodeSt.push(root);
        root = root->left;
      }

      if (!nodeSt.empty())
      {
        root = nodeSt.top();
        nodeSt.pop();
        res.push_back(root->val);
      }

      if (root->right != nullptr)
      {
        nodeSt.push(root->right);
        root = root->right;
      }
      
      return res;
    }
  };

  // int main()
  // {
  //   TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  //   (new Solution)->inorderTraversal(root);
  // }

  // @lc code=end
