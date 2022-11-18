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
    // 先将 nums 排序，可以省去哈希表的空间
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }

      int right = nums.size() - 1;

      for (int left = i + 1; left < right; left++)
      {

        if (left > i + 1 && nums[left] == nums[left - 1])
        {
          continue;
        }

        while (nums[left] + nums[right] + nums[i] > 0 && left < right)
        {
          /* code */
          right--;
        }

        if (left == right)
        {
          break;
        }

        if (nums[left] + nums[right] + nums[i] == 0)
        {
          res.push_back({nums[i], nums[left], nums[right]});
        }
      }
    }
    return res;
  }
};

// @lc code=end