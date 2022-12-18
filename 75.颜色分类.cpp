/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int p0 = 0;
    int p2 = nums.size() - 1;
    int i = 0;
    while (i <= p2)
    {
      if (nums[i] == 2)
      {
        int temp = nums[p2];
        nums[p2] = nums[i];
        nums[i] = temp;
        p2--;
        i--;
      }
      else if (nums[i] == 0)
      {
        int temp = nums[p0];
        nums[p0] = nums[i];
        nums[i] = temp;
        p0++;
      }
      i++;
    }
  }
};
// @lc code=end
