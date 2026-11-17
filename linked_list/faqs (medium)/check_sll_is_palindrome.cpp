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


// bruteforce -> TC: O(n ^ 2) | SC: O(n)
class Solution1 {
public:
    string getNumber(ListNode* head) {
        ListNode* temp= head;

        string num= "";

        while (temp) {
            num= num + to_string(temp->val);
            temp= temp->next;
        }

        return num;
    }

    bool isNumPalindrome(string num, int st, int end) {
        if (st > end) {
            return true;
        }

        if (num[st] != num[end]) {
            return false;
        }

        return isNumPalindrome(num, st + 1, end - 1);
    }

    bool isPalindrome(ListNode* head) {
        // egde case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // get the number represented in the sll
        string num= getNumber(head);
        int size= num.size();

        // check if its palindrome
        return isNumPalindrome(num, 0, size - 1);
    }
};

// vector approach -> TC: O(n ^ 2) | SC: O(n ^ 2)
class Solution2{
public:
    vector<int> getVector(ListNode* head) {
        ListNode* temp= head;
        vector<int> vec;

        while (temp) {
            vec.push_back(temp->val);
            temp= temp->next;
        }

        return vec;
    }

    bool isVectorPalindrome(vector<int> nums, int st, int end) {
        if (st > end) {
            return true;
        }

        if (nums[st] != nums[end]) {
            return false;
        }

        return isVectorPalindrome(nums, st + 1, end - 1);
    }

    bool isPalindrome(ListNode* head) {
        // egde case: no or single element
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // get the vector represented in the sll
        vector<int> nums= getVector(head);
        int size= nums.size();

        // check if its palindrome
        return isVectorPalindrome(nums, 0, size - 1);
    }
};

// optimal approach -> TC: O(n) | SC: O(1)
class Solution3 {
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

    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while (fast->next && fast->next->next) {
            slow= slow->next;
            fast= fast->next->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        // edge case: no or single elements
        if (!head || !head->next) {
            return true;
        }

        // reach the middle now
        ListNode* middleNode= middleOfLinkedList(head);

        // reverse the 2nd half
        ListNode* oldHead= middleNode->next; // head of 2nd half
        ListNode* newHead= reverseList(oldHead);

        // traverse both the halfs
        ListNode* f= head;
        ListNode* s= newHead;

        while (s) {
            if (f->val != s->val) {
                // revese the 2nd half again
                reverseList(newHead);

                return false;
            }

            f= f->next;
            s= s->next;
        }

        // revese the 2nd half again
        reverseList(newHead);

        return true;
    }
};