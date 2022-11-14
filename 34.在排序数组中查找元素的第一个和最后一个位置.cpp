/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{

public:
  int searchIt(vector<int> &nums, int target, int left, int right, bool flag)
  {

    if (left > right)
    {
      return -1;
    }

    int middle = left + (right - left) / 2;

    if (nums[middle] < target)
    {
      left = middle + 1;
      return searchIt(nums, target, left, right, flag);
    }
    else if (nums[middle] > target)
    {
      right = middle - 1;
      return searchIt(nums, target, left, right, flag);
    }
    else
    {
      // 找到一个下标，但是不能确定是否为第一个/最后一个位置，故继续向前/向后寻找（具体向前还是向后由 flag 决定），直到返回 -1
      if (flag)
      {
        // 向后寻找 MAX
        int MAX = searchIt(nums, target, middle + 1, right, flag);
        return MAX == -1 ? middle : MAX;
      }
      else
      {
        // 向前寻找 MIN
        int MIN = searchIt(nums, target, left, middle - 1, flag);
        return MIN == -1 ? middle : MIN;
      }
    }
  }

  vector<int> searchRange(vector<int> &nums, int target)
  {
    int MIN = searchIt(nums, target, 0, nums.size() - 1, false);
    int MAX = searchIt(nums, target, 0, nums.size() - 1, true);
    return {MIN, MAX};
  }
};

// @lc code=end