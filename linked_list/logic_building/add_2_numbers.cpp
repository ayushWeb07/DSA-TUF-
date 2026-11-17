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

// TC: O(max(M, N)), where M and N are the lengths of the two lists. | SC: O(max(M, N))
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
            ListNode* t1= linkedList1;
            ListNode* t2= linkedList2;

            ListNode* head= new ListNode(-1);
            ListNode* temp= head;
            ListNode* newNode= nullptr;

            int sum= 0, carry= 0;

            // both slls are present i.e. not exhausted
            while (t1 && t2) {

                // do the node wise sum
                sum+= carry;
                sum+= t1->data;
                sum+= t2->data;

                // create the new node inside the sll
                newNode= new ListNode(sum % 10);
                carry= sum / 10;

                temp->next= newNode;
                temp= newNode;

                // move the linked list pointers forward
                t1= t1->next;
                t2= t2->next;

                sum= 0;
            }

            // sll 2 got exhausted, but sll 1 is still present
            while (t1) {
                // do the node wise sum
                sum+= carry;
                sum+= t1->data;

                // create the new node inside the sll
                newNode= new ListNode(sum % 10);
                carry= sum / 10;

                temp->next= newNode;
                temp= newNode;

                // move the linked list pointer forward
                t1= t1->next;

                sum= 0;
            }

            // sll 1 got exhausted, but sll 2 is still present
            while (t2) {
                // do the node wise sum
                sum+= carry;
                sum+= t2->data;

                // create the new node inside the sll
                newNode= new ListNode(sum % 10);
                carry= sum / 10;

                temp->next= newNode;
                temp= newNode;

                // move the linked list pointer forward
                t2= t2->next;

                sum= 0;
            }

            // check if carry is present
            if (carry) {
                newNode= new ListNode(carry);

                temp->next= newNode;
                temp= newNode;
            }

            return head->next;
        }
};