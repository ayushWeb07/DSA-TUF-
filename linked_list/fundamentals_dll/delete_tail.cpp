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
    ListNode *deleteTail(ListNode *&head) {
        ListNode* temp= head;
        ListNode* tail= nullptr;

        // egde case: no elements in dll
        if (head == nullptr) {
            return nullptr;
        }

        // edge case: single element
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // reach the node before tail
        while (temp->next->next) {
            temp= temp->next;
        }

        // temp -> node before tail
        delete temp->next;
        temp->next= nullptr;

        return head;
    }
};