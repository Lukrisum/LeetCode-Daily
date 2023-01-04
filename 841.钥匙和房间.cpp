/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
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
  void dfs(vector<vector<int>> &rooms, int key, unordered_set<int> &s)
  {
    for (auto &&_key : rooms[key])
    {
      if (s.count(_key) == 0)
      {
        s.insert(_key);
        dfs(rooms, _key, s);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    unordered_set<int> s;

    s.insert(0);
    dfs(rooms, 0, s);

    for (int i = 0; i < rooms.size(); i++)
    {
      /* code */
      if (s.count(i) == 0)
      {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
