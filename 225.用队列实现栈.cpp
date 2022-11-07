/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyStack
{
private:
  queue<int> qI;
  queue<int> qII;

public:
  MyStack()
  {
    // nothing
  }

  void push(int x)
  {
    qII.push(x);
    while (!qI.empty())
    {
      qII.push(qI.front());
      qI.pop();
    }
    swap(qI, qII);
  }

  int pop()
  {
    int res = qI.front();
    qI.pop();
    return res;
  }

  int top()
  {
    return qI.front();
  }

  bool empty()
  {
    return qI.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
