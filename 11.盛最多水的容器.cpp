/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int maxContent = 0;
    // 左右指针分别向两端，移动短板，直到重合
    while (left < right)
    {
      int tempContent = min(height[left], height[right]) * (right - left);
      if (tempContent > maxContent)
      {
        maxContent = tempContent;
      }
      if (height[left] > height[right])
      {
        right--;
      }
      else
      {
        left++;
      }
    }
    return maxContent;
  }
};

// @lc code=end
