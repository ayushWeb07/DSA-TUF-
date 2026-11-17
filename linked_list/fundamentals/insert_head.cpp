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

// TC: O(1) | SC: O(1)
class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newNode= new ListNode(X);
        newNode->next= head;

        return newNode;
    }
};