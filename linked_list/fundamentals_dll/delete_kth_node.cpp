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

class Solution {
public:
 ListNode *deleteKthElement(ListNode *&head, int k) {
  int currK= 1;
  ListNode* temp= head;

  // edge case: no elements
  if (head == nullptr) {
   return nullptr;
  }

  // edge case: delete head
  if (k == 1) {
   head= head->next;

   if (head) {
    head->prev= nullptr;
   }

   delete temp;
   return head;
  }

  while (currK != k - 1) {
   temp= temp->next;
   currK++;
  }

  // reached the (k - 1)th node
  ListNode* kthNode= temp->next;
  temp->next= kthNode->next;

  if (kthNode->next) {
   kthNode->next->prev= temp;
  }

  delete kthNode;
  return head;
 }
};