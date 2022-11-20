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

    for (int left = 0; left < nums.size(); left++)
    {

      while (sum < target && right < nums.size())
      {
        sum += nums[right];
        right++;
      }
      
      if (sum >= target)
      {
        int len = (right - 1) - left + 1;
        if (minLen == 0)
        {
          minLen = len;
        }
        else
        {
          minLen = min(len, minLen);
        }
      }
      else
      {
        return minLen;
      }

      sum -= nums[left];
    }

    return minLen;
  }
};

// @lc code=end
