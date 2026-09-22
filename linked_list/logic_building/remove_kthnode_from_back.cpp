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

// Brute approach: TC - countNodes traverses the list once, taking O(L) time. deleteKthNode traverses up to the target's predecessor, taking O(L - n) time in the worst case. The total is O(L) asymptotically, although the list is traversed in two phases. | SC: O(n)
class Solution {
public:
    int countNodes(ListNode* head) {
        ListNode* temp= head;
        int c= 0;

        while (temp) {
            c++;
            temp= temp->next;
        }

        return c;
    }

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // count the no. of nodes
        int numNodes= countNodes(head);

        // make k -> to delete from front
        int k= (numNodes - n) + 1;

        // delete the kth node and get the head
        return deleteKthNode(head, k);
    }
};

// optimal approach: TC - The initial loop advances fast n times, and the second loop traverses the remaining portion of the list. Together, each relevant node is visited a constant number of times, resulting in O(L) time, where L is the number of nodes | SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast= head;
        ListNode* nodeToBeDeleted= nullptr;

        // move the fast node n times
        for (int i= 1; i<= n; i++) {
            fast= fast->next;
        }

        // edge case -> delete head
        if (fast == nullptr) {
            nodeToBeDeleted= head;

            head= head->next;
            delete nodeToBeDeleted;
            return head;
        }

        ListNode* slow= head;

        // traverse simultaneously till fast becomes the last node
        while (fast->next) {
            slow= slow->next;
            fast= fast->next;
        }

        nodeToBeDeleted= slow->next;

        slow->next= slow->next->next;
        delete nodeToBeDeleted;
        return head;
    }
};