/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (root == nullptr)
    {
      return res;
    }
    queue<TreeNode *> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty())
    {
      /* code */
      int size = nodeQue.size();
      vector<int> temp;
      for (int i = 0; i < size; i++)
      {
        /* code */
        root = nodeQue.front();
        nodeQue.pop();
        temp.push_back(root->val);
        if (root->left)
          nodeQue.push(root->left);
        if (root->right)
          nodeQue.push(root->right);
      }
      res.push_back(temp);
    }
    return res;
  }
};

// @lc code=end