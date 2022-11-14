/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return 0;
    }

    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
      int middle = left + (right - left) / 2;
      if (nums[middle] < nums[middle + 1])
      {
        left = middle + 1;
      }
      else
      {
        right = middle;
      }
    }

    return left;
  }
};

// @lc code=end
