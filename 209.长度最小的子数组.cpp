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

      sum += nums[left];

      while (sum < target && right < nums.size())
      {
        if (right == left)
        {
          right++;
        }

        if (right < nums.size())
        {
          sum += nums[right++];
        }
      }

      if (sum >= target)
      {
        int tempLen = right - left + 1;
        if (minLen == 0 || minLen > tempLen)
        {
          minLen = tempLen;
        }
        sum -= nums[left];
      }
      else
      {
        break;
      }
    }

    return minLen;
  }
};

// @lc code=end
