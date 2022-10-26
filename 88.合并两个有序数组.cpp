/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    if (m == 0)
    {
      nums1 = nums2;
      return;
    }
    else if (n == 0)
    {
      return;
    }

    vector<int> tempNums;
    int i = 0, j = 0;

    for (; i < m && j < n;)
    {
      if (nums1[i] < nums2[j])
      {
        tempNums.push_back(nums1[i]);
        i++;
      }
      else
      {
        tempNums.push_back(nums2[j]);
        j++;
      }
    }

    if (i == m)
    {
      for (; j < n; j++)
      {
        tempNums.push_back(nums2[j]);
      }
    }
    else
    {
      for (; i < m; i++)
      {
        tempNums.push_back(nums1[i]);
      }
    }

    nums1 = tempNums;
    return;
  }
};

// int main()
// {
//   vector<int> a, b;
//   a = {1, 2, 3, 0, 0, 0};
//   b = {2, 5, 6};
//   (new Solution())->merge(a, a.size() + b.size(), b, b.size());
//   return 0;
// }
// @lc code=end
