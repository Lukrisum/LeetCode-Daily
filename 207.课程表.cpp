/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int count = 0;
  bool dfs(int index, vector<vector<int>> &prerequisites, int numCourses, vector<bool> visited)
  {
    if (count == numCourses)
    {
      return true;
    }
    
    if (!visited[index])
    {
      for (auto &&i : prerequisites[index])
      {
        visited[i] = true;
        count++;
        dfs(i, prerequisites, numCourses, visited);
        count--;
        visited[i] = false;
      }
    }
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<bool> visited(prerequisites.size(), false);
    visited[0] = true;
    return dfs(0, prerequisites, numCourses, visited);
  }
};

// @lc code=end
