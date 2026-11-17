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
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newNode= new ListNode(X);

        // edge case: no elements in dll
        if (head == nullptr) {
            head= newNode;
            return head;
        }

        newNode->next= head;
        head->prev= newNode;
        head= newNode;

        return head;
    }
};