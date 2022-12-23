/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> mp0;
    unordered_map<string, char> mp1;

    vector<string> sList;
    string temp;

    for (int i = 0; i < s.length(); i++)
    {
      if (s.at(i) == ' ')
      {
        sList.push_back(temp);
        temp = "";
      }
      else
      {
        temp += s.at(i);
        if (i == s.length() - 1)
        {
          sList.push_back(temp);
        }
      }
    }

    if (sList.size() != pattern.length())
    {
      return false;
    }

    for (int i = 0; i < sList.size(); i++)
    {
      cout << sList.at(i);
      if ((mp0.count(pattern.at(i)) != 0 && mp0[pattern.at(i)] != sList.at(i)) || (mp1.count(sList.at(i)) != 0 && mp1[sList.at(i)] != pattern.at(i)))
      {
        return false;
      }

      mp0[pattern.at(i)] = sList.at(i);
      mp1[sList.at(i)] = pattern.at(i);
    }

    return true;
  }
};

// @lc code=end
