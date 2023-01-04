/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
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
class Solution
{
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    vector<int> in_range(n);
    vector<int> res;

    for (auto &&i : edges)
    {
      in_range[i[1]]++;
    }

    for (int i = 0; i < n; i++)
    {
      if (in_range[i] == 0)
      {
        res.push_back(i);
      }
    }

    return res;
  }
};
// @lc code=end
