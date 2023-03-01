/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
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
  string frequencySort(string s)
  {
    unordered_map<char, int> mp;
    for (auto &&c : s)
    {
      mp[c]++;
    }

    struct cmp
    {
      bool operator()(pair<char, int> &p1, pair<char, int> &p2)
      {
        return p1.second < p2.second;
      }
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;

    for (auto &&i : mp)
    {
      q.push(i);
    }

    string res;
    while (!q.empty())
    {
      int count = q.top().second;
      while (count > 0)
      {
        res += q.top().first;
        count--;
      }

      q.pop();
    }

    return res;
  }
};
// @lc code=end
