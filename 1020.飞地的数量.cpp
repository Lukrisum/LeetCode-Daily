/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
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
  bool dfs(vector<vector<int>> &grid, int i, int j, int &count)
  {
    if (grid[i][j] == 0)
    {
      return true;
    }

    if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
    {
      return false;
    }

    count++;
    grid[i][j] = 0;

    bool up = dfs(grid, i - 1, j, count);
    bool left = dfs(grid, i, j - 1, count);
    bool right = dfs(grid, i, j + 1, count);
    bool down = dfs(grid, i + 1, j, count);

    return up && left && right && down;
  }

  int numEnclaves(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size(), sum = 0;

    for (int i = 1; i < m - 1; i++)
    {
      for (int j = 1; j < n - 1; j++)
      {
        if (grid[i][j] == 1)
        {
          int count = 0;
          if (dfs(grid, i, j, count))
          {
            sum += count;
          }
        };
      }
    }
    return sum;
  }
};
// @lc code=end
