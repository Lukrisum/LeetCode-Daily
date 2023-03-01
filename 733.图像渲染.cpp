/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
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
  void dfs(vector<vector<int>> &image, int sr, int sc, int color, int target)
  {
    if (image[sr][sc] == color)
    {
      return;
    }
    image[sr][sc] = color;

    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto &&i : delta)
    {
      int nx_row = sr + i.first;
      int nx_col = sc + i.second;

      if (nx_row < image.size() && nx_row > -1 && nx_col < image[0].size() && nx_col > -1 && image[nx_row][nx_col] == target)
      {
        dfs(image, nx_row, nx_col, color, target);
      }
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
  }
};

// @lc code=end
