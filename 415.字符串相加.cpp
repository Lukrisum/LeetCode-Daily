/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    string s = "";
    bool beforeTen = 0;
    while (num1 != "" || num2 != "" || beforeTen != 0)
    {
      string temp1 = "0";
      string temp2 = "0";
      if (num1 != "")
      {
        temp1 = num1.back();
        num1.pop_back();
      }
      if (num2 != "")
      {
        temp2 = num2.back();
        num2.pop_back();
      }

      int tempRes = stoi(temp1) + stoi(temp2) + beforeTen;
      beforeTen = tempRes / 10;
      int tempOne = tempRes % 10;

      s = to_string(tempOne) + s;
    }
    return s;
  }
};

// @lc code=end
