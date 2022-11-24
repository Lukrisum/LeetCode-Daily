/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<vector<int>> res;
  vector<int> temp;

  void dfs(vector<vector<int>> graph, int node)
  {  

    if (node == graph.size() - 1)
    {
      res.push_back(temp); 
      return;
    }
    
    for (auto &&nextNode : graph[node])
    {
      temp.push_back(nextNode);  
      dfs(graph, nextNode);
      temp.pop_back();
    }

  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    temp.push_back(0);
    dfs(graph,0);
    return res;
  }
};

// @lc code=end
