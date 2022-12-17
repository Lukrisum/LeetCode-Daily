/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> res;

    // 特判
    if (nums.size() < 3)
    {
      return res;
    }

    // 先将 nums 排序，可以省去哈希表的空间
    sort(nums.begin(), nums.end());

    // i 遍历，i 的右边进行双指针
    for (int i = 0; i < nums.size() - 2; i++)
    {
      /* code */
      if (nums[i] > 0)
      {
        return res;
      }

      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }

      int right = nums.size() - 1;

      for (int left = i + 1; left < right;)
      {
        if (nums[i] + nums[left] + nums[right] == 0)
        {
          res.push_back({nums[i], nums[left], nums[right]});

          while (left < right && nums[left] == nums[left + 1])
          {
            left++;
          }

          while (left < right && nums[right] == nums[right - 1])
          {
            right--;
          }
          left++;
          right--;
        }
        else if (nums[i] + nums[left] + nums[right] > 0)
        {
          right--;
        }
        else if (nums[i] + nums[left] + nums[right] < 0)
        {
          left++;
        }
      }
    }

    return res;
  }
};

// @lc code=end