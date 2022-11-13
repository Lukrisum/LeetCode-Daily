/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
  int findDepth(TreeNode *root, int depth)
  {
    if (root == nullptr)
    {
      return depth - 1;
    }

    return max(findDepth(root->left, depth + 1), findDepth(root->right, depth + 1));
  }

  bool isBalanced(TreeNode *root)
  {
    int depth = 1;

    if (root == nullptr)
    {
      return true;
    }

    queue<TreeNode *> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty())
    {
      /* code */
      int size = nodeQue.size();
      for (int i = 0; i < size; i++)
      {
        /* code */
        root = nodeQue.front();
        nodeQue.pop();
        if (abs(findDepth(root->left, depth) - findDepth(root->right, depth)) > 1)
        {
          return false;
        }
        if (root->left)
          nodeQue.push(root->left);
        if (root->right)
          nodeQue.push(root->right);
      }
      depth++;
    }

    return true;
  }
};

// @lc code=end