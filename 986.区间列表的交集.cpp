/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
  {
    vector<vector<int>> res;
    int i = 0;
    int j = 0;
    while (i < firstList.size() && j < secondList.size())
    {
      int left = max(firstList[i][0], secondList[j][0]);
      int right = min(firstList[i][1], secondList[j][1]);

      if (right == firstList[i][1])
      {
        i++;
      }
      else
      {
        j++;
      }

      if (left <= right)
      {
        res.push_back({left, right});
      }

    }
    return res;
  }
};
// @lc code=end
