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
 void deleteGivenNode(ListNode *node) {
  node->prev->next= node->next;

  if (node->next) {
   node->next->prev= node->prev;
  }

  delete node;
 }
};