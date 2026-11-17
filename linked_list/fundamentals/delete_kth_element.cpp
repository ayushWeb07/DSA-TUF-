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

// TC: O(k) where k is the target position because the loop traverses exactly k-2 nodes to reach the node preceding the target. | SC: O(1)
class Solution {
public:
    ListNode* deleteKthNode(ListNode* &head, int k) {
        int currK= 1;
        ListNode* temp= head;

        // edge case: delete head
        if (k == 1) {
            head= head->next;
            delete temp;
            return head;
        }

        while (currK != k - 1) {
            temp= temp->next;
            currK++;
        }

        // reached the (k - 1)th node
        ListNode* kthNode= temp->next;
        temp->next= kthNode->next;
        delete kthNode;
        return head;
    }
};