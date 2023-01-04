/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
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
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> in_range(n + 1);
    vector<int> out_range(n + 1);

    for (int i = 0; i < trust.size(); i++)
    {
      in_range[trust[i][1]]++;
      out_range[trust[i][0]]++;
    }

    for (int i = 1; i < n + 1; i++)
    {
      /* code */
      if (in_range[i] == n - 1 && out_range[i] == 0)
      {
        return i;
      }
    }

    return -1;
  }
};
// @lc code=end
