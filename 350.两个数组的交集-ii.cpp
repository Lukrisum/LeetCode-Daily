/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> nums3;
    vector<int> res;

    for (auto &&i : nums1)
    {
      nums3[i]++;
    }

    for (auto &&i : nums2)
    {
      if (nums3[i] > 0)
      {
        res.push_back(i);
        nums3[i]--;
      }
    }

    // for (auto &&i : nums1.size() > nums2.size() ? nums1 : nums2)
    // {
    //   if (nums3[i] > 1)
    //   {
    //     for (int j = 0; j < nums3[i]; j++)
    //       res.push_back(i);
    //   }
    // }
    return res;
  }
};

// @lc code=end
