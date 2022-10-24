/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> s;
    for (auto &&i : nums)
    {
      s.insert(i);
    }
    return s.size() != nums.size();
  }
};
// @lc code=end
