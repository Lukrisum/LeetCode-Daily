/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    for (auto &&row : matrix)
    {
      int l = 0;
      int r = row.size() - 1;
      while (l <= r)
      {
        int mid = r - (r - l) / 2;
        if (row[mid] == target)
        {
          return true;
        }
        else if (row[mid] > target)
        {
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
    }

    return false;
  }
};

// @lc code=end
