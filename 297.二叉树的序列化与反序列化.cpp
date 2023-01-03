/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
  void dfs(TreeNode *root, string &str_pre)
  {
    if (!root)
    {
      str_pre +=  "None,";
      return;
    }

    str_pre += to_string(root->val) + ",";
    dfs(root->left, str_pre);
    dfs(root->right, str_pre);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string str_pre;
    dfs(root, str_pre);
    return str_pre;
  }

  TreeNode *buildBiTreeByPre(queue<string> &qu)
  {
    if (qu.front() == "None")
    {
      qu.pop();
      return nullptr;
    }

    TreeNode *root = new TreeNode(stoi(qu.front()));
    qu.pop();
    root->left = buildBiTreeByPre(qu);
    root->right = buildBiTreeByPre(qu);

    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    queue<string> qu;
    string temp;
    for (auto &&c : data)
    {
      if (c == ',')
      {
        qu.push(temp);
        temp = "";
      }
      else
      {
        temp += c;
      }
    }

    qu.push(temp);

    return buildBiTreeByPre(qu);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
