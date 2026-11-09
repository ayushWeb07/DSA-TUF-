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
    int llLength(ListNode* head) {
        // no ll
        if (!head) return 0;

        // single element
        if (!head->next) return 1;

        ListNode* temp= head;
        int l= 0;

        while (temp) {
            l++;
            temp= temp->next;
        }

        return l;
    }

    int getLength(ListNode* head) {
        return llLength(head);
    }
};