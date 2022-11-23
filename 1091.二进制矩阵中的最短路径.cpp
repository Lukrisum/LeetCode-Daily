/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */
#include <bits/stdc++.h>
using namespace std;
int i = 0;
// @lc code=start
class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int n = grid.size();
    if (n == 1)
    {
      return 1;
    }

    int res = 1;
    queue<pair<int, int>> q;

    q.push({0, 0});

    vector<pair<int, int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    vector<vector<int>> visited(n, vector<int>(n, false));

    while (!q.empty())
    {
      int size = q.size();
      res++;

      for (int i = 0; i < size; i++)
      {
        pair<int, int> pos = q.front();
        int posI = pos.first;
        int posJ = pos.second;

        for (int j = 0; j < 8; j++)
        {
          int ni = posI + delta[j].first;
          int nj = posJ + delta[j].second;
          if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0 && !visited[i][j])
          {
            if (ni == n - 1 && nj == n - 1)
            {
              return res;
            }
            q.push({ni, nj});
            visited[ni][nj] = true;
          }
        }
      }
    }

    return -1;
  }
};

// @lc code=end
