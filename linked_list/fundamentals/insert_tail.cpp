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
    ListNode* insertAtTail(ListNode* &head, int X) {
        ListNode* newNode= new ListNode(X);

        // edge case: no nodes
        if (head == nullptr) {
            head= newNode;
            return head;
        }

        // edge case: single node
        if (head->next == nullptr) {
            head->next= newNode;
            return head;
        }

        // traverse to the last node
        ListNode* temp= head;

        while (temp->next) {
            temp= temp->next;
        }

        temp->next= newNode;
        return head;
    }
};