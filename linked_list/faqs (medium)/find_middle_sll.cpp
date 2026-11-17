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

// bruteforce -> TC: O(2 * n) | SC: O(1)
class Solution {
public:
    int countNodes(ListNode* head) {
        ListNode* temp= head;
        int cnt= 0;

        while (temp) {
            cnt++;
            temp= temp->next;
        }

        return cnt;
    }

    ListNode* findKthNode(ListNode* head, int k) {
        int currK= 1;
        ListNode* temp= head;

        // edge case: find head
        if (k == 1) {
            return head;
        }

        while (currK != k) {
            temp= temp->next;
            currK++;
        }

        // reached the kth node
        return temp;
    }

    ListNode* middleOfLinkedList(ListNode* head) {
        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // count the no. of nodes
        int n= countNodes(head);

        // find the middle node
        ListNode* middleNode= findKthNode(head, (n / 2) + 1);

        return middleNode;
    }
};

// optimal -> TC: O(n) | SC: O(1)
class Solution {
public:
    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while (fast && fast->next) {
            slow= slow->next;
            fast= fast->next->next;
        }

        return slow;
    }
};