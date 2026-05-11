#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // vector creation
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // display approach 1
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << endl;

    // display approach 2
    vector<int>::iterator it1= vec.begin();

    while (it1 != vec.end()) {
        cout << *it1 << " ";
        it1++;
    }

    cout << endl;

    // display approach 3
    for (auto it2= vec.begin(); it2 != vec.end(); it2++) {
        cout << *it2 << " ";
    }

    return 0;
}