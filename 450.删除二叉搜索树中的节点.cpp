/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == nullptr)
    {
      return root;
    }

    if (root->val > key)
    {
      root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
      root->right = deleteNode(root->right, key);
    }
    else
    {
      if (root->left == nullptr)
      {
        root = root->right;
      }
      else if (root->right == nullptr)
      {
        root = root->left;
      }
      else
      {
        TreeNode *head = root->right;
        while (head->left)
        {
          head = head->left;
        }
        root->right = deleteNode(root->right, head->val);
        head->left = root->left;
        head->right = root->right;
        root = head;
      }
    }

    return root;
  }
};

// @lc code=end
