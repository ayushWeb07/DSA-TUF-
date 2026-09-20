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

class Solution {
public:
    vector<int> LLTraversal(ListNode *head) {
        vector<int> ans;

        ListNode* temp= head;

        while (temp) {
            ans.push_back(temp->data);
            temp= temp->next;
        }

        return ans;
    }
};