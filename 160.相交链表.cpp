/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    unordered_set<ListNode *> s;
    while (headA != nullptr || headB != nullptr)
    {
      
      /* code */
      if (headA != nullptr)
      {
        if(s.count(headA) == 1){
          return headA;
        }
        s.insert(headA);
        headA = headA->next;
      }

      if (headB != nullptr)
      {
        if(s.count(headB) == 1){
          return headB;
        }
        s.insert(headB);
        headB = headB->next;
      }
    }

    return nullptr;
  }
};
// @lc code=end
