/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    // int c = 0;
    // vector<int> temp;
    // for (int r = 0; r < numRows; r++)
    // {
    //   if (c == 0 || c == r)
    //   {
    //     temp.push_back(1);
    //   }
    //   else
    //   {
    //     temp.push_back(res[r - 1][c - 1] + res[r - 1][c]);
    //   }

    //   if (c++ == r)
    //   {
    //     res.push_back(temp);
    //     vector<int> emptyNums;
    //     temp = emptyNums;
    //     c = 0;
    //   }
    // }
    for (int i = 0; i < numRows; i++)
    {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; j++)
      {
        row[j] = res[i - 1][j] + res[i - 1][j - 1];
      }
      res.push_back(row);
    }
    return res;
  }
};

// int main()
// {
//   (new Solution())->generate(5);
//   return 0;
// }
// @lc code=end
