#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
class ListNode{

  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

// TC: O(n) | SC: O(1)
class Solution {
public:
    ListNode* deleteTail(ListNode* &head) {
        ListNode* temp= head;
        ListNode* tail= nullptr;

        // edge case: single element
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        while (temp->next && temp->next->next) {
            temp= temp->next;
        }

        // temp -> node before the tail
        tail= temp->next;
        temp->next= nullptr;

        // free up tail
        delete tail;

        return head;
    }
};