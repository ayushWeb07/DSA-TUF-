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
    ListNode* reverseDLL(ListNode* head) {
        if (!head) return head;

        if (!head->next) return head;

        ListNode* curr= head;
        ListNode* prev;
        ListNode* next;

        while (curr) {
            prev= curr->prev;
            next= curr->next;

            curr->next= prev;
            curr->prev= next;

            curr= next;
        }

        if (prev) {
            head= prev->prev;
        }

        return head;
    }
};