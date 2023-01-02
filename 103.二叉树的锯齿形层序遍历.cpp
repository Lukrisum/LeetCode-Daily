/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    if (root == nullptr)
    {
      return {};
    }

    int flag = true;
    deque<TreeNode *> qu;
    vector<vector<int>> res;

    qu.push_back(root);

    while (!qu.empty())
    {
      int n = qu.size();
      vector<int> temp;

      for (int i = 0; i < n; i++)
      {
        if (flag)
        {
          root = qu.front();
          qu.pop_front();
          temp.push_back(root->val);

          if (root->left)
          {
            qu.push_back(root->left);
          }
          if (root->right)
          {
            qu.push_back(root->right);
          }
        }
        else
        {
          root = qu.back();
          qu.pop_back();
          temp.push_back(root->val);

          if (root->right)
          {
            qu.push_front(root->right);
          }
          if (root->left)
          {
            qu.push_front(root->left);
          }
        }
      }
      res.push_back(temp);
      flag = !flag;
    }

    return res;
  }
};
// @lc code=end
