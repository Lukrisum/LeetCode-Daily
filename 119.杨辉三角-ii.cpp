/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    vector<vector<int>> res;
    for (int i = 0; i <= rowIndex; i++)
    {
      vector<int> temp;
      for (int j = 0; j <= i; j++)
      {
        if (j == 0 || j == i)
        {
          temp.push_back(1);
        }
        else
        {
          temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
      }
      res.push_back(temp);
    }
    return res[rowIndex];
  }
};

// @lc code=end
