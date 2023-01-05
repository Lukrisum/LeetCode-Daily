/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
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
  void maxHeapify(vector<int> &nums, int i, int heapSize)
  {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if (left < heapSize && nums[left] > nums[largest])
    {
      largest = left;
    }

    if (right < heapSize && nums[right] > nums[largest])
    {
      largest = right;
    }

    if (largest != i)
    {
      swap(nums[i], nums[largest]);
      maxHeapify(nums, largest, heapSize);
    }
  }

  int findKthLargest(vector<int> &nums, int k)
  {
    int heapSize = nums.size();
    // 煎堆，自底而上 O(n)
    for (int i = heapSize / 2; i >= 0; i--)
    {
      maxHeapify(nums, i, heapSize);
    }

    // 堆排序 O(nlogn)
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
    {
      /* code */
      swap(nums[0], nums[i]);
      heapSize--;
      maxHeapify(nums, 0, heapSize);
    }

    return nums[0];
  }
};
// @lc code=end
