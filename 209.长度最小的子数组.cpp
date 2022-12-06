/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int minLen = 0;
    int right = 0;
    int sum = 0;

    for (int left = 0; left < nums.size() - 1; left++)
    {
      sum += nums[left];

      while (sum < target && right < nums.size() - 1)
      {
        if (right == left)
        {
          if (right == nums.size() - 1)
          {
            return minLen;
          }
          right++;
        }
        sum += nums[right++];
      }

      if (sum >= target)
      {
        int tempMin = (right - 1) - left + 1;
        minLen = (minLen == 0 ? tempMin : min(tempMin, minLen));
      }

      sum -= nums[left];
    }
    return minLen;
  }
};

// @lc code=end
