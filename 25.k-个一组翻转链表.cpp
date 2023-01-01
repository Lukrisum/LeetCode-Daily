/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    int len = 0;
    ListNode *cur = head;
    while (cur != nullptr)
    {
      len++;
      cur = cur->next;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *p0 = dummy;

    ListNode *pre;
    cur = head;

    while (len >= k)
    {
      len -= k;
      for (int i = 0; i < k; i++)
      {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }

      ListNode *nxt = p0->next;
      p0->next->next = cur;
      p0->next = pre;
      p0 = nxt;
    }

    return dummy->next;
  }
};
// @lc code=end
