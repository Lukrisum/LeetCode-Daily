/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  vector<vector<int>> collector;
  void helper(TreeNode *root, int target, int sum, vector<int> temp)
  {
    if (root == nullptr)
    {
      return;
    }

    temp.push_back(root->val);
    sum += root->val;

    if (root->left == nullptr && root->right == nullptr)
    {
      if (sum == target)
      {
        collector.push_back(temp);
      }
      temp.pop_back();
      return;
    }

    if (root->left)
    {
      helper(root->left, target, sum, temp);
    }

    if (root->right)
    {
      helper(root->right, target, sum, temp);
    }
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<int> temp;
    helper(root, targetSum, 0, temp);
    return collector;
  }
};

// @lc code=end
