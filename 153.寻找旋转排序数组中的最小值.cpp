/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int foo(vector<int> nums, int left, int right)
  {

    if (left >= right)
    {
      return left;
    }

    int middle = left + (right - left) / 2;

    // 最小值在 middle 右侧
    if (nums[middle] > nums[right])
    {
      return foo(nums, middle + 1, right);
    }
    else // 最小值在 middle 左侧
    {
      return foo(nums, left, middle);
    }
  }

  int findMin(vector<int> &nums)
  {
    return nums[foo(nums, 0, nums.size() - 1)];
  }
};

// @lc code=end
