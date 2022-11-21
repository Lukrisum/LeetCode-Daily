/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int circleCount = 0;
    int cities = isConnected.size();
    vector<int> visited(cities);

    for (int i = 0; i < cities; i++)
    {
      if (!visited[i])
      {
        circleCount++;
        visited[i] = 1;
        
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
          int curCity = q.front();
          q.pop();

          for (int j = 0; j < cities; j++)
          {
            if (!visited[j])
            {
              if (isConnected[curCity][j] == 1)
              {
                visited[j] = 1;
                q.push(j);
              }
            }
          }
        }
      }
    }

    return circleCount;
  }
};

// @lc code=end