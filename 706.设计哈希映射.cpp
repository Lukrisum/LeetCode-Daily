/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyHashMap
{
public:
  vector<vector<int>> inner;

  MyHashMap()
  {
  }

  void put(int key, int value)
  {
    for (auto &&i : inner)
    {
      if (i[0] == key)
      {
        i[1] = value;
        return;
      }
    }
    inner.push_back({key, value});
  }

  int get(int key)
  {
    for (auto &&i : inner)
    {
      if (i[0] == key)
      {
        return i[1];
      }
    }
    return -1;
  }

  void remove(int key)
  {
    for (auto i = inner.begin(); i != inner.end(); i++)
    {
      if ((*i)[0] == key)
      {
        inner.erase(i);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
