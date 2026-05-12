#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(3);
    s.insert(7);
    s.insert(2);

    for (int ele: s) {
        cout << ele << " ";
    }

    cout << endl;

    // find for 10
    auto it= s.find(10);

    if (it == s.end()) {
        cout << "Search failed";
    } else {
        cout << "Search succeeded";
    }


    return 0;
}