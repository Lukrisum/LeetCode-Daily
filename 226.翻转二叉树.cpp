/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
  void dfs(TreeNode *root)
  {
  }

  TreeNode *invertTree(TreeNode *root)
  {
    queue<TreeNode *> nodeQue;
    nodeQue.push(root);

    while (!nodeQue.empty())
    {
      /* code */
      int size = nodeQue.size();
      for (int i = 0; i < size; i++)
      {
        /* code */
        TreeNode * tempRoot = nodeQue.front();
        if(tempRoot == nullptr){
          return root;
        }
        nodeQue.pop();
        TreeNode* temp = tempRoot->left;
        tempRoot->left = tempRoot->right;
        tempRoot->right = temp;
        if (tempRoot->left)
          nodeQue.push(tempRoot->left);
        if (tempRoot->right)
          nodeQue.push(tempRoot->right);
      }
    }
    return root;
  }
};

// @lc code=end
