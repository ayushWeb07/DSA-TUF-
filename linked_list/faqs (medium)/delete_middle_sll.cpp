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
    ListNode* deleteMiddle(ListNode* head) {
        // edge case: no element
        if (head == nullptr) {
            return nullptr;
        }

        // edge case: single element
        if (head->next == nullptr) {
            ListNode* temp= head;
            head= head->next;
            delete temp;
            return head;
        }

        // find the node previous to middle now
        ListNode* fast= head;
        ListNode* slow= head;
        ListNode* prev= head;

        while (fast && fast->next) {
            prev= slow;

            slow= slow->next;
            fast= fast->next->next;
        }

        // delete the middle node
        prev->next= slow->next;
        delete slow;
        return head;
    }
};