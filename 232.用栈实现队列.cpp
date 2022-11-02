/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyQueue
{
public:
  stack<int> stIn;
  stack<int> stOut;

  MyQueue()
  {
  }

  void push(int x)
  {
    stIn.push(x);
  }

  int pop()
  {
    if (stOut.empty())
    {
      update();
    }
    int res = stOut.top();
    stOut.pop();
    return res;
  }

  int peek()
  {
    if (stOut.empty())
    {
      update();
    }
    return stOut.top();
  }

  bool empty()
  {
    return stIn.empty() && stOut.empty();
  }

  void update()
  {
    while (!stIn.empty())
    {
      stOut.push(stIn.top());
      stIn.pop();
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
