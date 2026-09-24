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

// bruteforce -> TC: O(n) | SC: O(1)
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

    ListNode *addOne(ListNode *head) {
        // edge case: no elements
        if (head == nullptr) {
            return nullptr;
        }

        // reverse the sll
        ListNode* revHead= reverseList(head);

        // do then node wise sum
        int sum= 0, carry= 1;
        ListNode* temp= revHead;

        while (temp) {
            // do the sum
            sum+= carry;
            sum+= temp->val;

            // update the node and carry
            temp->val= sum % 10;
            carry= sum / 10;

            // no change is required in the next subsequent nodes
            if (carry == 0 ){
                break;
            }

            temp= temp->next;
            sum= 0;
        }

        // sll exhausted but carry is still present
        if (carry) {
            ListNode* newNode= new ListNode(1);
            newNode->next= revHead;
            revHead= newNode;
            return revHead;
        }

        // reverse the sll
        ListNode* orgHead= reverseList(revHead);
        return orgHead;
    }
};

// optimal -> TC: O(n) | SC: O(n)
class Solution {
public:
    int getCarry(ListNode* temp) {
        // base case: null node
        if (temp == nullptr) {
            return 1;
        }

        // get the carry and do the sum
        int carry= getCarry(temp->next);
        int sum= carry + temp->val;

        // update the nodes value
        temp->val= sum % 10;
        carry= sum / 10;

        return carry;
    }

    ListNode *addOne(ListNode *head) {
        // edge case: no elements
        if (head == nullptr) {
            return nullptr;
        }

        // call the get carry recursive function
        int carry= getCarry(head);

        if (carry == 1) {
            ListNode* newNode= new ListNode(1);
            newNode->next= head;
            head= newNode;
            return head;
        }

        return head;
    }
};
