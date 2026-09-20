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

// TC: O(K) where K is the target position because the loop iterates K-2 times to reach the node preceding the target position | SC: O(1)
class Solution {
public:
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
        ListNode* newNode= new ListNode(X);
        ListNode* temp= head;
        int currK= 1;

        // edge case: no nodes
        if (head == nullptr) {
            head= newNode;
            return head;
        }

        // edge case: insert at head
        if (K == 1) {
            newNode->next= head;
            head= newNode;
            return head;
        }

        while (currK != K - 1) {
            temp= temp->next;
            currK++;
        }

        // reached the (k - 1)th node
        newNode->next= temp->next;
        temp->next= newNode;
        return head;
    }
};