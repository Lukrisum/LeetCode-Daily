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
  int num;

  void dfs(vector<vector<int>> &rooms, int key)
  {
    rooms[key].push_back(-1);
    num++;

    for (auto &&_key : rooms[key])
    {
      if (_key == -1)
      {
        return;
      }

      int len = rooms[_key].size();
      if (len == 0 || rooms[_key][len - 1] != -1)
      {
        dfs(rooms, _key);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    dfs(rooms, 0);
    return num == rooms.size();
  }
};
// @lc code=end
