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

// TC: O(K) because the algorithm iterates through the list until the (K-1)th position using a while loop that performs K-2 iterations. | SC: O(1)
class Solution {
public:
 ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
  ListNode* newNode= new ListNode(X);
  ListNode* temp= head;
  int currK= 1;

  // edge case: no elements in dll
  if (head == nullptr) {
   head= newNode;
   return head;
  }

  // edge case: insert at head
  if (K == 1) {
   newNode->next= head;
   head->prev= newNode;
   head= newNode;
   return head;
  }

  // reach the (k - 1)th node
  while (currK != K - 1) {
   temp= temp->next;
   currK++;
  }

  // reached the (k - 1)th node
  newNode->next= temp->next;
  newNode->prev= temp;

  temp->next= newNode;

  if(newNode->next) {
   newNode->next->prev= newNode;
  }

  return head;
 }
};