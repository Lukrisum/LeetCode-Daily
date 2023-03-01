/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
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
  void dfs(vector<vector<int>> &grid, int m, int n, int &sum)
  {
    if (m < 0 || m > grid.size() - 1 || n < 0 || n > grid[0].size() - 1 || grid[m][n] == 0)
    {
      return;
    }

    sum++;
    grid[m][n] = 0;
    dfs(grid, m, n + 1, sum);
    dfs(grid, m, n - 1, sum);
    dfs(grid, m + 1, n, sum);
    dfs(grid, m - 1, n, sum);
  }

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    int res = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          int a = 0;
          dfs(grid, i, j, a);
          res = max(res, a);
        }
      }
    }

    return res;
  }
};
// @lc code=end
