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

// Better apporoach: TC - O(n) | SC: O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* &head) {
        ListNode* temp= head;
        vector<int> nums;

        // create the nums vector
        while (temp) {
            nums.push_back(temp->data);
            temp= temp->next;
        }

        int n= nums.size();
        temp= head;

        // fill the odd indices nodes
        for (int i= 0; i < n; i+= 2) {
            temp->data= nums[i];
            temp= temp->next;
        }

        // fill the even indices nodes
        for (int i= 1; i < n; i+= 2) {
            temp->data= nums[i];
            temp= temp->next;
        }

        return head;
    }
};

// optimal apporoach: TC - O(n) | SC: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* &head) {
        // edge case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* oddTemp= head;
        ListNode* evenTemp= head->next;
        ListNode* firstEven= head->next;

        while (evenTemp && evenTemp->next) {
            oddTemp->next= oddTemp->next->next;
            oddTemp= oddTemp->next;

            evenTemp->next= evenTemp->next->next;
            evenTemp= evenTemp->next;
        }

        // update next of the last odd
        oddTemp->next= firstEven;
        return head;
    }
};
