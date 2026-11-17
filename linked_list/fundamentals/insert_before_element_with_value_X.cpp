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
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        ListNode* temp= head;
        ListNode* prev= nullptr;
        ListNode* newNode= new ListNode(val);

        // edge case: no nodes
        if (head == nullptr) {
            head= newNode;
            return head;
        }

        // insert at head
        if (head->data == X) {
            newNode->next= head;
            head= newNode;
            return head;
        }

        // reach the node previous to the node with X
        while (temp && temp->data != X) {
            prev= temp;
            temp= temp->next;
        }

        // check if no such node exists
        if (temp == nullptr) {
            return head;
        }

        newNode->next= temp;
        prev->next= newNode;
        return head;
    }
};