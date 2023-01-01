/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  void reorderList(ListNode *head)
  {
    if (head->next == nullptr)
    {
      return;
    }

    stack<ListNode *> st;

    ListNode *cur = head;
    while (cur != nullptr)
    {
      st.push(cur);
      cur = cur->next;
    }

    cur = head;
    while (1)
    {
      ListNode *toInsert = st.top();
      st.pop();
      cout << cur->val << ":" << toInsert->val << endl;
      if (cur == toInsert || cur->next == toInsert)
      {
        cout << toInsert->val;
        toInsert->next = nullptr;
        return;
      }
      else
      {
        ListNode *nxt = cur->next;
        cur->next = toInsert;
        toInsert->next = nxt;
      }
      cur = cur->next->next;
    }
  }
};
// @lc code=end
