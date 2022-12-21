/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return 1;
    }

    int res = 1;

    // DP00(Time Limit Exceeded): dp[i] 维护以 i 开头的，最长递增序列的长度
    vector<int> dp(nums.size(), 0);
    dp[nums.size() - 1] = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (i < nums.size() - 1)
      {
        dp[i] = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
          if (nums[i] < nums[j])
          {
            dp[i] = max(dp[j] + 1, dp[i]);
          }
          if (dp[i] > res)
          {
            res = dp[i];
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
