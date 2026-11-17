#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* next;

    Node(int val) {
        data= val;
        next= nullptr;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};
    int n= arr.size();

    // create the head node
    Node* head= new Node(arr[0]);
    Node* temp= head;

    for (int i= 1; i< n; i++) {
        // create the new node
        Node* newNode= new Node(arr[i]);

        // link the temp node's next pointer
        temp->next= newNode;

        // update the next pointer
        temp= newNode;
    }

    // traverse the linked list
    temp= head;

    while (temp) {
        cout << temp->data << " ";
        temp= temp->next;
    }

    return 0;
}

