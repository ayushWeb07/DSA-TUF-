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

// TC - O(n) | SC: O(1)
class Solution {
public:
    ListNode* sortList(ListNode* &head) {
        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp= head;
        int c0= 0, c1= 0, c2= 0;

        // count the no of 0s, 1s, 2s
        while (temp) {
            if (temp->data == 0) {
                c0++;
            }

            else if (temp->data == 1) {
                c1++;
            }

            else {
                c2++;
            }

            temp= temp->next;
        }

        temp= head; // reset the temp node to head

        // fill 0s
        while (c0) {
            temp->data= 0;
            temp= temp->next;
            c0--;
        }

        // fill 1s
        while (c1) {
            temp->data= 1;
            temp= temp->next;
            c1--;
        }

        // fill 2s
        while (c2) {
            temp->data= 2;
            temp= temp->next;
            c2--;
        }

        return head;
    }
};