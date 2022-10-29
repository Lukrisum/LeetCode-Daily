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
    for (int r = 0; r < numRows; r++)
    {
      vector<int> temp;
      for (int c = 0; c <= r; c++)
      {
        if (c == 0 || c == r)
        {
          temp.push_back(1);
        }
        else
        {
          temp.push_back(res[r - 1][c - 1] + res[r - 1][c]);
        }
      }
      res.push_back(temp);
    }
    return res;
  }
};

// int main()
// {
//   vector<vector<int>> x = ((new Solution())->generate(5));
//   printf("%d\n", x[2][1]);
//   return 0;
// }

// @lc code=end
