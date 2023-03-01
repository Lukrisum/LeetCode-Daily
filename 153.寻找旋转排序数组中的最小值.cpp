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
    int middle = left + (right - left) / 2;

    if (nums[middle] > nums[right])
    {
      return foo(nums, middle + 1, right);
    }
    else if (nums[middle] < nums[right])
    {
      return foo(nums, left, middle);
    }
    else
    {
      return middle;
    }
  }

  int findMin(vector<int> &nums)
  {
    int target = foo(nums, 0, nums.size() - 1);
    return nums[target];
  }
};

// @lc code=end
