/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == '1')
        {
          islands++;
          grid[i][j] = '2';
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty())
          {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
              int r = p.first + offsets[k];
              int c = p.second + offsets[k + 1];
              if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
              {
                grid[r][c] = '2';
                q.push({r, c});
              }
            }
          }
        }
      }
    }
    return islands;
  }
};
// @lc code=end