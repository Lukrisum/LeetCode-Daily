/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return 0;
    }

    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
      int middle = left + (right - left) / 2;
      if (nums[middle] < nums[middle + 1])
      {
        left = middle + 1;
      }
      else
      {
        right = middle;
      }
    }

    return left;
  }
};

// @lc code=end