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

// bruteforce -> TC: O(n log n) | SC: O(n)
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        // edge case: no or single element
        if (!head || !head->next) {
            return false;
        }

        ListNode* temp= head;
        map<ListNode*, int> f;

        while (temp) {
            auto it= f.find(temp);

            if (it != f.end()) {
                return true;
            }

            f[temp]++;
            temp= temp->next;
        }

        return false;
    }
};

// optimal -> TC: O(n) | SC: O(1)
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        // egde case: no or single element
        if (!head || !head->next) {
            return false;
        }

        ListNode* f= head;
        ListNode* s= head;

        while (f && f->next) {
            s= s->next;
            f= f->next->next;

            if (s == f) {
                return true;
            }
        }

        return false;
    }
};