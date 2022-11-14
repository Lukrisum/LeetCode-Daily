/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    int left = 0;
    int right = rowSize * colSize - 1;

    vector<int> nums;
    while (left <= right)
    {

      int middle = left + (right - left) / 2;
      int midRow = middle / colSize;
      int midCol = middle % colSize;

      if (matrix[midRow][midCol] > target)
      {
        right = middle - 1;
      }
      else if (matrix[midRow][midCol] < target)
      {
        left = middle + 1;
      }
      else
      {
        return true;
      }
    }

    return false;
  }
};

// @lc code=end
