/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyLinkedList
{
private:
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
  };

  int len;
  ListNode *dummy;

public:
  MyLinkedList()
  {
    dummy = new ListNode(0);
    len = 0;
  }

  int get(int index)
  {
    if (index >= len || index < 0)
    {
      return -1;
    }

    int i = 0;
    ListNode *cur = dummy->next;

    while (cur != nullptr)
    {
      if (i == index)
      {
        return cur->val;
      }
      cur = cur->next;
      i++;
    }

    return -1;
  }

  void addAtHead(int val)
  {
    ListNode *newHead = new ListNode(val);
    newHead->next = dummy->next;
    dummy->next = newHead;
    len++;
  }

  void addAtTail(int val)
  {
    ListNode *cur = dummy;
    ListNode *newTail = new ListNode(val);

    while (cur->next != nullptr)
    {
      cur = cur->next;
    }

    cur->next = newTail;
    len++;
  }

  void addAtIndex(int index, int val)
  {
    if (index > len || index < 0)
    {
      return;
    }

    int i = 0;
    ListNode *cur = dummy->next;
    ListNode *pre = dummy;

    ListNode *newNode = new ListNode(val);
    while (cur != nullptr)
    {
      /* code */
      if (i == index)
      {
        newNode->next = pre->next;
        pre->next = newNode;
        len++;
        return;
      }
      pre = cur;
      cur = cur->next;
      i++;
    }

    newNode->next = pre->next;
    pre->next = newNode;
    len++;
  }

  void deleteAtIndex(int index)
  {
    if (index >= len || index < 0)
    {
      return;
    }

    int i = 0;
    ListNode *cur = dummy->next;
    ListNode *pre = dummy;

    while (cur != nullptr)
    {
      /* code */
      if (i == index)
      {
        pre->next = pre->next->next;
        len--;
        return;
      }
      pre = cur;
      cur = cur->next;
      i++;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
