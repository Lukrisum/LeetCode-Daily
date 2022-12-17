/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      ans = ans ^ nums[i];
    }

    return ans;
  }
};

// @lc code=end