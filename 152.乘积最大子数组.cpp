/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    // int dp[20000] = {0};
    // int maxPro = nums[0];
    // dp[nums.size() - 1] = nums[nums.size() - 1];
    // for (int i = nums.size() - 1; i >= 0; i--)
    // {
    //   /* code */
    //   if (i < nums.size() - 1)
    //   {
    //     dp[i] = max(nums[i], nums[i] * dp[i + 1]);
    //   }
    //   if (maxPro < dp[i])
    //   {
    //     maxPro = dp[i];
    //   }
    // }

    // return maxPro;

    // 精选
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); ++i)
    {
      maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
      minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
  }
};

// @lc code=end
