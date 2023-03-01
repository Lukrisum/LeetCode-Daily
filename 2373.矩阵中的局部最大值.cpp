/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
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
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int m = grid.size();
        vector<vector<int>> res(m - 2, vector<int>(m - 2, 0));
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {  
                        res[i][j] = max(grid[k][l],res[i][j]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
