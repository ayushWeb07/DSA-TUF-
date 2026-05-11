#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    list<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_back(4);

    for (auto ele: lst) {
        cout << ele << " ";
    }

    return 0;
}