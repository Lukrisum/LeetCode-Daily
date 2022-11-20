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
    int isLandCount = 0;

    queue<vector<int>> q;

    int row = 0;
    int col = 0;

    q.push({row, col});

    while (!q.empty())
    {
      vector<int> tempPos = q.front();
      q.pop();

      int r = tempPos[0];
      int c = tempPos[1];

      if (grid[r][c] == '1')
      {
        grid[r][c] = '2';

        isLandCount++;

        queue<vector<int>> qInner;
        qInner.push({r, c});

        while (!qInner.empty())
        {
          vector<int> tempPos = qInner.front();
          qInner.pop();

          int rInner = tempPos[0];
          int cInner = tempPos[1];

          if (rInner < grid.size() - 1 && grid[rInner + 1][cInner] == '1')
          {
            grid[rInner + 1][cInner] = '2';
            qInner.push({rInner + 1, cInner});
          }

          if (cInner < grid[0].size() - 1 && grid[rInner][cInner + 1] == '1')
          {
            grid[rInner][cInner + 1] = '2';
            qInner.push({rInner, cInner + 1});
          }

          if (rInner > 0 && grid[rInner - 1][cInner] == '1')
          {
            grid[rInner - 1][cInner] = '2';
            qInner.push({rInner - 1, cInner});
          }

          if (cInner > 0 && grid[rInner][cInner - 1] == '1')
          {
            grid[rInner][cInner - 1] = '2';
            qInner.push({rInner, cInner - 1});
          }
        }
      }

      if (r < grid.size() - 1)
      {
        q.push({r + 1, c});
      }

      if (c < grid[0].size() - 1)
      {
        q.push({r, c + 1});
      }
    }

    return isLandCount;
  }
};

// @lc code=end
