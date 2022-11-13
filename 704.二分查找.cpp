/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int searchIt(vector<int> &nums, int target, int left, int right)
  {

    if (left > right)
    {
      return -1;
    }

    int middle = left + (right - left) / 2;

    if (nums[middle] < target)
    {
      left = middle + 1;
    }
    else if (nums[middle] > target)
    {
      right = middle - 1;
    }
    else
    {
      return middle;
    }

    return searchIt(nums, target, left, right);
  }

  int search(vector<int> &nums, int target)
  {
    return searchIt(nums, target, 0, nums.size() - 1);
  }
};

// @lc code=end