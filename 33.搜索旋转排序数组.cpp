/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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

    if (nums[middle] == target)
    {
      return middle;
    }

    // 右侧有序
    if (nums[middle] < nums[right])
    {
      int res = searchIt(nums, target, middle + 1, right);
      if (res != -1)
      {
        return res;
      }
      return searchIt(nums, target, left, middle - 1);
    }
    else // 左侧有序
    {
      int res = searchIt(nums, target, left, middle - 1);
      if (res != -1)
      {
        return res;
      }
      return searchIt(nums, target, middle + 1, right);
    }
  }

  int search(vector<int> &nums, int target)
  {
    return searchIt(nums, target, 0, nums.size() - 1);
  }
};

// @lc code=end
