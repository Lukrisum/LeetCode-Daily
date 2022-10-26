/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int i = 0;
    for (auto &&num : nums)
    {
      if (i == 0 || num > nums[i - 1])
      {
        nums[i++] = num;
      }
    }
    return i;
  }
};

// @lc code=end
