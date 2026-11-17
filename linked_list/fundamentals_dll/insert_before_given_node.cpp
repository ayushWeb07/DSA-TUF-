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

// TC: O(1) | SC: O(1)
class Solution {
public:
 void insertBeforeGivenNode(ListNode* node, int X) {
  ListNode* newNode= new ListNode(X);

  // no element in dll
  if (node == nullptr) {
   node= newNode;
   return;
  }

  newNode->next= node;
  newNode->prev= node->prev;

  if (node->prev) {
   node->prev->next= newNode;
  }

  node->prev= newNode;
 }
};