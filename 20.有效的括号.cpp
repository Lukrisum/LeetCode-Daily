/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  bool isValid(string s)
  {
    // stack<char> st;
    // for (auto &&c : s)
    // {
    //   if ((c == '(') || (c == '[') || (c == '{'))
    //   {
    //     st.push(c);
    //   }
    //   else
    //   {
    //     if (st.empty() || (st.top() == '(' && c != ')') || (st.top() == '[' && c != ']') || (st.top() == '{' && c != '}'))
    //     {
    //       return false;
    //     }
    //     else
    //     {
    //       st.pop();
    //     }
    //   }
    // }
    // return st.empty();

    stack<char> st;
    for (auto &&c : s)
    {
      if (!st.empty() && ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '{' && c == '}')))
      {
        st.pop();
      }
      else
      {
        st.push(c);
      }
    }
    return st.empty();
  }
};
// @lc code=end
