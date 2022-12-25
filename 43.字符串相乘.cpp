/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
    {
      return "0";
    }
    string ans = "0";

    reverse(num1.begin(),num1.end());
    for (int i = 0; i < num2.size(); i++)
    {
      int n = num2.at(i) - '0';

      int added = 0;
      string temp = "";
      for (auto &&c1 : num1)
      {
        int m = c1 - '0';
        int res = n * m + added;
        added = res / 10;
        temp = to_string(res % 10) + temp;
      }
      if(added > 0){
        temp = to_string(added) + temp;
      }

      for (int j = 0; j < num2.size() - i - 1; j++)
      {
        temp.push_back('0');
      }
      
      ans = addStrings(ans, temp);
    }

    return ans;
  }

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
