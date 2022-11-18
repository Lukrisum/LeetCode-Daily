/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    // 不存在子数组的乘积严格小于 k
    if (k <= 1)
    {
      return 0;
    }

    int res = 0;
    // 寻找所有以右节点结尾的，符合题意的子数组
    // 枚举右指针（并不是 dp，从左边开始，方便记录 prod）
    int left = 0;
    int prod = 1;
    for (int right = 0; right < nums.size(); ++right)
    {
      prod *= nums[right];
      while (prod >= k)
      {
        prod /= nums[left++];
      }
      res += right - left + 1;
    }
    return res;
  }
};

// @lc code=end
