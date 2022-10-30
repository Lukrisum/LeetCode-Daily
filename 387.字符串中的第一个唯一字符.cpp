/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> countMap;
    int i = 0;
    string temp;
    for (auto &&c : s)
    {
      if (countMap[c] == 0)
      {
        temp += c;
      }
      countMap[c] += 1;
    }

    char resChar = 'L';
    int resIndex = -1;

    for (auto &&c : temp)
    {
      if (countMap[c] == 1)
      {
        resChar = c;
        break;
      }
    }

    if (resChar == 'L')
    {
      return resIndex;
    }

    for (int i = 0; i < s.length(); i++)
    {
      /* code */
      if (s.at(i) == resChar)
      {
        resIndex = i;
        break;
      }
    }

    return resIndex;
  }
};

// int main()
// {
//   (new Solution())->firstUniqChar("loveleetcode");
//   return 0;
// }
// @lc code=end
