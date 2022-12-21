/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int sum = 0;

    vector<int> prefixSum(nums.size() + 1);
    prefixSum[0] = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
      sum += mp[prefixSum[i + 1] - k];
      mp[prefixSum[i + 1]]++;
    }

    return sum;
  }
};

// @lc code=end
