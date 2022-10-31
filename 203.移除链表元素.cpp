/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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

 */
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *resHead = new ListNode(-1);
    ListNode *tempHead = resHead;
    while (head != nullptr)
    {
      /* code */
      if (head->val != val)
      {
        tempHead->next = head;
        tempHead = tempHead->next;
      }
      head = head->next;
    }

    if (tempHead->next != nullptr && tempHead->next->val == val)
    {
      tempHead->next = nullptr;
    }

    return resHead->next;
  }
};

// @lc code=end
