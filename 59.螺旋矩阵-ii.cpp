/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    // 模拟：遇到边界/标记过的顺时针转动 90°
    // 四个方向
    vector<pair<int, int>> deltaPos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int posFlag = 0;
    vector<vector<int>> res(n, vector<int>(n));

    int row = 0;
    int col = 0;
    for (int i = 1; i <= n * n; i++)
    {
      res[row][col] = i;
      int nextRow = row + deltaPos[posFlag].first;
      int nextCol = col + deltaPos[posFlag].second;
      if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || res[nextRow][nextCol] != 0)
      {
        // 顺时针 90°
        posFlag = (posFlag + 1) % 4;
      }
      row += deltaPos[posFlag].first;
      col += deltaPos[posFlag].second;
    }
    return res;
  }
};

// @lc code=end
