/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr)
    { 
      return false;
    }
    unordered_set<ListNode *> some;
    while (head->next != nullptr)
    {
      if (some.count(head) > 0)
      {
        return true;
      }
      some.insert(head);
      head = head->next;
    }
    return false;
  }
};
// @lc code=end
