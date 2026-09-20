#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

// TC: O(n) | SC: O(1)
class Solution {
public:
 ListNode* insertBeforeTail(ListNode* head, int X) {
  ListNode* newNode= new ListNode(X);
  ListNode* temp= head;

  // edge case: no elements in dll
  if (head == nullptr) {
   head= newNode;
   return head;
  }

  // edge case: single element in dll
  if (head->next == nullptr) {
   head->prev= newNode;
   newNode->next= head;
   head= newNode;
   return head;
  }

  // reach the node before tail
  while (temp->next->next != nullptr) {
   temp= temp->next;
  }

  newNode->next= temp->next;
  newNode->prev= temp;
  temp->next->prev= newNode;
  temp->next= newNode;

  return head;
 }
};