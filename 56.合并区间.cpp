/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (intervals.size() == 0)
      return {{}};
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (auto &&i : intervals)
    {
      if (res.empty())
      {
        res.push_back(i);
      }
      else
      {
        if (res.back()[1] >= i[0])
        {
          vector<int> temp;
          temp.push_back(res.back()[0]);
          temp.push_back(max(i[1], res.back()[1]));
          res.pop_back();
          res.push_back(temp);
        }
        else
        {
          res.push_back(i);
        }
      }
    }
    return res;
  }
};

// @lc code=end
