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

// Brute approach: TC - O(n) | SC: O(n)
class Solution {
public:
    vector<int> makeVector(ListNode* head) {
        vector<int> ans;
        ListNode* temp= head;

        while (temp) {
            ans.push_back(temp->val);
            temp= temp->next;
        }

        return ans;
    }

    ListNode* reverseList(ListNode* head) {
        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // create a vector containing then list elements
        vector<int> vec= makeVector(head);

        // reverse the vector
        reverse(vec.begin(), vec.end());

        // update the list
        ListNode* temp= head;
        int i= 0;

        while (temp) {
            temp->val= vec[i];
            temp= temp->next;
            i++;
        }

        return head;
    }
};

// optimal approach: TC - O(n) | SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev= nullptr;
        ListNode* temp= head;
        ListNode* next= nullptr;

        while (temp) {
            next= temp->next;
            temp->next= prev;
            prev= temp;
            temp= next;
        }

        return prev;
    }
};