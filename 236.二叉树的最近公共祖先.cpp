/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || root == p || root == q)
    {
      return root;
    }

    TreeNode *l_node = lowestCommonAncestor(root->left, p, q);
    TreeNode *r_node = lowestCommonAncestor(root->right, p, q);

    return l_node == nullptr ? r_node : r_node == nullptr ? l_node: root;
  }
};
// @lc code=end
