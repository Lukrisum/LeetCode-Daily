/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    // 暴力法
    // map<int, int> m;
    // for (auto &&i : nums)
    // {
    //   m[i]++;
    // }

    // for (auto &&i : m)
    // {
    //   if (i.second > nums.size() / 2)
    //   {
    //     return i.first;
    //   }
    // }

    // 摩尔投票法
    int cand_num = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (count == 0)
      {
        cand_num = nums[i];
        count = 1;
      }
      else if (nums[i] == cand_num)
      {
        count++;
      }
      else
      {
        count--;
      }
    }

    return cand_num;
  }
};

// @lc code=end
