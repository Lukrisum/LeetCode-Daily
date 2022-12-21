/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> res;
    vector<int> L(nums.size(), 0), R(nums.size(), 0);
    L[0] = 1;
    R[nums.size() - 1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      L[i] = L[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      R[i] = R[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
      res.push_back(L[i] * R[i]);
    }

    return res;
  }
};

// @lc code=end
