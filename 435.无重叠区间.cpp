/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    if (intervals.size() == 1)
    {
      return 0;
    }

    int ans = 1;

    sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
         { return u[1] < v[1]; });

    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] >= right)
      {
        ++ans;
        right = intervals[i][1];
      }
    }
    return intervals.size() - ans;
  }
};

// @lc code=end
