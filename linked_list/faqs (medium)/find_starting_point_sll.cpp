#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

// optimal -> TC: O(n) | SC: O(1)
class Solution {
public:
    ListNode *findStartingPoint(ListNode *head) {
        // edge case: no or single element
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* f= head;
        ListNode* s= head;

        while (f && f->next) {
            s= s->next;
            f= f->next->next;

            if (s == f) {
                s= head;

                while (s != f) {
                    s= s->next;
                    f= f->next;
                }

                return s;
            }
        }

        return nullptr;
    }
};