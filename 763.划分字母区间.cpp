/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
      mp[s.at(i)] = i;
    }

    vector<int> res;
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.length(); i++)
    {
      end = max(end, mp[s.at(i)]);
      cout << i << " " << end << endl;
      if (i == end)
      {
        res.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return res;
  }
};
// @lc code=end
