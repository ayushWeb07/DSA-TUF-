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
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
        ListNode* temp= head;
        ListNode* prev= nullptr;

        // edge case: delete the head
        if (head->data == X) {
            head= head->next;
            delete temp;
            return head;
        }

        while (temp && temp->data != X) {
            prev= temp;
            temp= temp->next;
        }

        // check if such element was never existed
        if (temp == nullptr) {
            return head;
        }

        // temp -> node whose value = X
        prev->next= temp->next;
        delete temp;
        return head;
    }
};