/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
  {
    int oR = mat.size();
    int oC = mat[0].size();
    vector<vector<int>> res;

    if (r * c != oC * oR)
    {
      return mat;
    }

    int j = 0;
    vector<int> temp;

    for (auto &&row : mat)
    {
      for (auto &&i : row)
      {
        temp.push_back(i);
        j++;
        if (j == c)
        {
          res.push_back(temp);
          vector<int> tempTemp;
          temp = tempTemp;
          j = 0;
        }
      }
    }

    return res;
  }
};

// @lc code=end
