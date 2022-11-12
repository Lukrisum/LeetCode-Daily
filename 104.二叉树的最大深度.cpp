/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
  int result;
  void getDepth(TreeNode *root, int depth)
  {
    result = depth > result ? depth : result;

    if (!(root->left || root->right))
    {
      return;
    }

    if (root->left)
    {
      depth++;
      getDepth(root->left, depth);
      depth--;
    }

    if (root->right)
    {
      depth++;
      getDepth(root->right, depth);
      depth--;
    }
  }

  int findDepth(TreeNode *root, int depth)
  {
    if (root == nullptr)
    {
      return depth - 1;
    }

    return max(findDepth(root->left, depth + 1), findDepth(root->right, depth + 1));
  }

  int maxDepth(TreeNode *root)
  {
    // 递归法
    if (root == NULL)
      return 0;
    // getDepth(root, 1);
    // return result;
    return findDepth(root, 1);

    // 迭代法
    // vector<vector<int>> res;
    // if (root == nullptr)
    // {
    //   return res.size();
    // }
    // queue<TreeNode *> nodeQue;
    // nodeQue.push(root);
    // while (!nodeQue.empty())
    // {
    //   /* code */
    //   int size = nodeQue.size();
    //   vector<int> temp;
    //   for (int i = 0; i < size; i++)
    //   {
    //     /* code */
    //     root = nodeQue.front();
    //     nodeQue.pop();
    //     temp.push_back(root->val);
    //     if (root->left)
    //       nodeQue.push(root->left);
    //     if (root->right)
    //       nodeQue.push(root->right);
    //   }
    //   res.push_back(temp);
    // }
    // return res.size();
  }
};

// @lc code=end