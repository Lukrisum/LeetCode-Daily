/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {

    int maxPro = nums[0];

    int dpMax[20000] = {0};
    int dpMin[20000] = {0};

    dpMax[nums.size() - 1] = nums[nums.size() - 1];
    dpMin[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      /* code */
      if (i < nums.size() - 1)
      {

        // Your runtime beats 93.6 % of cpp submissions
        dpMax[i] = max(nums[i], max(nums[i] * dpMin[i + 1], nums[i] * dpMax[i + 1]));
        dpMin[i] = min(nums[i], min(nums[i] * dpMin[i + 1], nums[i] * dpMax[i + 1]));

        // Your runtime beats 58.5 % of cpp submissions
        if (nums[i] < 0)
        {
          dpMax[i] = max(nums[i], nums[i] * dpMin[i + 1]);
          dpMin[i] = min(nums[i], nums[i] * dpMax[i + 1]);
        }
        else
        {
          dpMax[i] = max(nums[i], nums[i] * dpMax[i + 1]);
          dpMin[i] = min(nums[i], nums[i] * dpMin[i + 1]);
        }
      }

      if (maxPro < dpMax[i])
      {
        maxPro = dpMax[i];
      }
    }

    return maxPro;
  }
};

// @lc code=end
