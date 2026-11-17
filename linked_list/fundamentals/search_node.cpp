#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Defination of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

// TC: O(n) | SC: O(1)
class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        // no list
        if (!head) return false;

        // head is the key
        if (head->val == key) return true;

        ListNode* temp= head;

        while (temp) {
            if (temp->val == key) {
                return true;
            }

            temp= temp->next;
        }

        return false;
    }
};