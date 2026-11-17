#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

// TC: O(n) | SC: O(n)
class Solution
{
public:
    ListNode *arrayToDoublyLinkedList(vector<int> &arr) {
        int n= arr.size();

        // edge case: no elements in the vector
        if (n == 0) {
            return nullptr;
        }

        ListNode* head= new ListNode(arr[0]);
        ListNode* temp= head;

        for (int i= 1; i< n; i++) {
            // create the new node
            ListNode* newNode= new ListNode(arr[i]);

            temp->next= newNode;
            newNode->prev= temp;

            temp= newNode;
        }

        return head;
    }
};
