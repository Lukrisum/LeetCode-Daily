/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
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
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    struct cmp
    {
      bool operator()(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
      {
        return p1.second < p2.second;
      }
    };

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> q;

    for (auto &&i : points)
    {
      int dis_square = i[0] * i[0] + i[1] * i[1];
      q.push({{i[0], i[1]}, dis_square});
      if (q.size() > k)
      {
        q.pop();
      }
    }

    vector<vector<int>> res;

    while (!q.empty())
    {
      res.push_back({q.top().first.first, q.top().first.second});
      q.pop();
    }

    return res;
  }
};
// @lc code=end
