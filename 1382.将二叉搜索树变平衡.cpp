/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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

  void dfs(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    dfs(root->left);
    res.push_back(root->val);
    dfs(root->right);
  }

  TreeNode *balanceBST(TreeNode *root)
  {
    dfs(root);
    return helper(res, 0, res.size() - 1);
  }

  TreeNode *helper(vector<int> res, int left, int right)
  {
    if (left > right)
    {
      return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(res[mid]);
    root->left = helper(res, left, mid - 1);
    root->right = helper(res, mid + 1, right);
    return root;
  }
};
// @lc code=end
