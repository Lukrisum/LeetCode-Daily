/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
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
  void dfs(vector<vector<int>> &grid, int r, int c, bool &flag)
  {
    int m = grid.size(), n = grid[0].size(), offsets[] = {0, 1, 0, -1, 0};

    if (r < 0 || c < 0 || r > m - 1 || r > n - 1 || grid[r][c] != 0)
    {
      return;
    }

    if (r == 0 || r == m - 1 || c == 0 || c == n - 1)
    {
      flag = false;
    }

    grid[r][c] = 1;
    for (int k = 0; k < 4; k++)
    {
      dfs(grid, r + offsets[k], c + offsets[k + 1], flag);
    }
  }

  int closedIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = m ? grid[0].size() : 0, island = 0;

    for (int i = 1; i < m - 1; i++)
    {
      for (int j = 1; j < n - 1; j++)
      {
        if (grid[i][j] == 0)
        {
          bool flag = true;
          dfs(grid, i, j, flag);
          if (flag)
          {
            island++;
          }
        }
      }
    }

    return island;
  }
};
// @lc code=end
