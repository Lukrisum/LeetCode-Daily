/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
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
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> mp;

    for (auto &&i : nums)
    {
      mp[i]++;
    }

    struct cmp
    {
      bool operator()(pair<int, int> &p1, pair<int, int> &p2)
      {
        return p1.second > p2.second; // 小顶堆是大于号
      }
    };
    // 创建优先队列
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

    for (auto &&i : mp)
    {
      q.push(i);
      if (q.size() > k)
      {
        q.pop();
      }
    }

    vector<int> res;
    while (!q.empty())
    {
      /* code */
      res.emplace_back(q.top().first);
      q.pop();
    }

    return res;
  }
};
// @lc code=end
void heapSort(vector<int> &nums);
void maxHeapify(vector<int> &nums, int i, int heapSize);

int main()
{
  vector<int> nums = {1, 3, 2, 4, 7, 8, 9, 4, 8, 9, 10};

  heapSort(nums);

  for (auto &&i : nums)
  {
    cout << i << " ";
  }

  return 0;
}

void heapSort(vector<int> &nums)
{
  int heapSize = nums.size();

  for (int i = nums.size() / 2; i >= 0; i--)
  {
    maxHeapify(nums, i, heapSize);
  }

  for (int i = heapSize - 1; i >= 0; i--)
  {
    /* code */
    swap(nums[0], nums[i]);
    maxHeapify(nums, 0, i);
  }
}

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
    swap(nums[largest], nums[i]);
    maxHeapify(nums, largest, heapSize);
  }
}
