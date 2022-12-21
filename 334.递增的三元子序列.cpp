/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool increasingTriplet(vector<int> &nums)
  {
    // 模拟
    if (nums.size() < 3)
    {
      return false;
    }

    int min = INT_MAX;
    int mid = INT_MAX;

    for (auto &&i : nums)
    {
      if (i <= min)
      {
        min = i;
      }
      else if (i <= mid)
      {
        mid = i;
      }
      else if (i > mid)
      {
        return true;
      }
    }

    return false;

    // DP00(Time Limit Exceeded: 76/77): dp[i] 维护以 i 开头的，最长递增序列的长度
    // vector<int> dp(nums.size(), 0);
    // dp[nums.size() - 1] = 1;
    // for (int i = nums.size() - 1; i >= 0; i--)
    // {
    //   if (i < nums.size() - 1)
    //   {
    //     dp[i] = 1;
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //       if (nums[i] < nums[j])
    //       {
    //         dp[i] = max(dp[j] + 1, dp[i]);
    //       }
    //       if (dp[i] == 3)
    //       {
    //         return true;
    //       }
    //     }
    //   }
    // }
    // return false;

    // DP01（❌）

  }
};
// @lc code=end
