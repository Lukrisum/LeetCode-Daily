/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    /***
     * 将 nums[i] 作为首个元素的子数组
     */
    int dp[100000];
    int res = nums[0];
    dp[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (i == nums.size() - 1)
      {
        dp[i] = nums[i];
      }
      else
      {
        dp[i] = max(nums[i], dp[i + 1] + nums[i]);
      }
      if (res < dp[i])
      {
        res = dp[i];
      }
    }
    return res;
  }
};

// @lc code=end
