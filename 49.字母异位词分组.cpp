/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t
    {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num)
                        { return (acc << 1) ^ fn(num); });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
    for (auto &&str : strs)
    {
      array<int, 26> count{};
      for (auto &&c : str)
      {
        count[c - 'a']++;
      }
      mp[count].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      /* code */
      ans.push_back(it->second);
    }
    return ans;
  }
};
// @lc code=end
